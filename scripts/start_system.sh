#Launch the configurer
nohup build/apps/Configurers/configurerPC  >> build/output/configurer.txt &

sleep 1

scripts/launch_brokers.sh 2

# sleep 1

# nohup build/apps/Consumers/watcher /home/thomas/ThomasGithub/embedded_kafka/node_server/monitor/ /home/thomas/ThomasGithub/embedded_kafka/build/conf/ >> build/output/watcher.txt &

# #nohup build/apps/Consumers/processAndProduce  >> build/output/processingConsumer.txt &

# sleep 1

# nohup build/apps/Producers/periodicProducer  >> build/output/periodicProducer.txt &
