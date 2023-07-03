#include <iostream>
#include <fstream>
#include <vector>
#include "json.hpp"

using json = nlohmann::json;

class OtherObject {
public:
  std::string name;
  int age;
};

class MyClass {
public:
  std::vector<OtherObject> objects;

  void from_json(const json& j) {
    objects = j.at("objects").get<std::vector<OtherObject>>();
  }
};

int main() {
  std::ifstream file("data.json");
  if (!file.is_open()) {
    std::cerr << "Failed to open JSON file." << std::endl;
    return 1;
  }

  json j;
  file >> j;

  MyClass obj;
  obj.from_json(j);

  for (const auto& otherObj : obj.objects) {
    std::cout << "Name: " << otherObj.name << ", Age: " << otherObj.age << std::endl;
  }

  return 0;
}
