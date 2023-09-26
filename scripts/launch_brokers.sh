#!/bin/bash

script_to_run="build/apps/Brokers/brokerPC"
brokers_count="$1"
port=1234

for ((i = 1; i <= brokers_count; i++)); do
  output_file="build/output/output_broker_$port.txt"
  nohup "$script_to_run" "$port" >> "$output_file" &
  port=$((port + 1))
done
