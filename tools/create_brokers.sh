#!/bin/bash

json_data=$(cat ../build/conf/configFile.json)

brokers_count=$(echo "$json_data" | jq '.brokers | length')

for ((i = 0; i < brokers_count; i++)); do
  broker=$(echo "$json_data" | jq -r ".brokers[$i]")
  endpoint=$(echo "$broker" | jq -r '.endpoint')
  port=$(echo "$endpoint" | jq -r '.port')
  
  command=$(echo '../build/apps/broker ' $port)

  output_file="../build/output/output_broker_$port.txt"

  topics_count=$(echo "$broker" | jq '.topics | length')

  for ((j = 0; j < topics_count; j++)); do
    topic=$(echo "$broker" | jq -r ".topics[$j]")
    topic_name=$(echo "$topic" | jq -r ".name")
    command+=" $topic_name"
  done

  nohup $command >> "$output_file" 2>&1 &

done
