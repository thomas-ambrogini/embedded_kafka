#include "Consumer.hpp"
#include "StandardOutputLogger.hpp"
#include "CommunicationType.hpp"
#include <chrono>
#include <thread>
#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include "json.hpp"
#include <vector>

using json = nlohmann::json;

void usage()
{
    std::cout << "Usage: ./watcher MonitorPath TopicFilePath [Configurer port]" << std::endl;
}

std::vector<std::string> parse_json(const std::string &topicFilePath, const std::string &monitorPath)
{
    std::vector<std::string> result;

    std::ifstream file(topicFilePath + "topics.json");
    if (!file.is_open())
    {
        std::cerr << "Failed to open the JSON file." << std::endl;
    }

    json jsonData;
    file >> jsonData;
    file.close();

    if (!jsonData.is_array())
    {
        std::cerr << "JSON data is not an array." << std::endl;
    }

    for (const auto &obj : jsonData)
    {
        if (obj.contains("name"))
        {
            std::string name = monitorPath + obj["name"].get<std::string>() + ".txt";
            result.push_back(name);
        }
        else
        {
            std::cerr << "Object does not have a 'name' field." << std::endl;
        }
    }

    return result;
}

std::string getTopicName(const std::string &filepath)
{
    size_t lastSlashPos = filepath.find_last_of('/');
    size_t dotPos = filepath.find_last_of('.');

    if (lastSlashPos != std::string::npos && dotPos != std::string::npos && lastSlashPos < dotPos)
    {
        std::string fileName = filepath.substr(lastSlashPos + 1, dotPos - lastSlashPos - 1);
        return fileName;
    }
    else
    {
        std::cerr << "Invalid file path format." << std::endl;
    }
}

void monitorFile(const std::string &filepath)
{
    StandardOutputLogger logger;
    CommunicationType commType = CommunicationType::UDP;
    int bootstrapBrokerPort = 12345;

    BrokerMetadata bootstrapBroker(new UDPEndpoint(bootstrapBrokerPort));
    Consumer consumer(commType, logger, bootstrapBroker, false);

    TopicMetadata topic(getTopicName(filepath));
    consumer.subscribe(topic);

    std::ofstream outputFile(filepath);
    if (!outputFile.is_open())
    {
        std::cerr << "Error opening the file." << std::endl;
    }

    while (true)
    {
        Record record = consumer.poll(topic);
        if (record.getData() != "NOT VALID")
        {
            outputFile << record.getData() << std::endl;
            std::cout << record.getData() << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    outputFile.close();
}

int main(int argc, char *argv[])
{
    StandardOutputLogger logger;
    CommunicationType commType = CommunicationType::UDP;
    int bootstrapBrokerPort = 12345;
    std::string topicName = "Prova";
    std::string monitorPath = "/home/thomas/embedded_kafka/node_server/monitor/";
    std::string topicFilePath = "/home/thomas/embedded_kafka/build/conf/";

    if (argc == 1)
    {
    }
    else if (argc < 3 || argc > 4)
    {
        usage();
        return 1;
    }
    else if (argc == 3)
    {
        monitorPath = argv[1];
        topicFilePath = argv[2];
    }
    else if (argc == 4)
    {
        monitorPath = argv[1];
        topicFilePath = argv[2];
        try
        {
            bootstrapBrokerPort = std::stoi(argv[3]);
        }
        catch (const std::exception &)
        {
            logger.logError("Invalid format of the boostrap broker port");
        }
    }

    std::vector<std::string> filesToMonitor = parse_json(topicFilePath, monitorPath);

    std::vector<std::thread> threads;
    for (const std::string &fileToMonitor : filesToMonitor)
    {
        threads.emplace_back(monitorFile, fileToMonitor);
    }

    for (std::thread &thread : threads)
    {
        thread.join();
    }

    return 0;
}
