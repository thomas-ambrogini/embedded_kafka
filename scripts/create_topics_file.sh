#!/bin/bash

# Create an array to store the input strings as objects
json_array=()
target_directory="build/conf"
json_file="$target_directory/topics.json"

# Iterate through the command-line arguments and add them to the array
for ((i=1; i<=$#; i++)); do
    key="arg$i"
    value="${!i}"
    json_object="{\"name\":\"$value\"}"
    json_array+=("$json_object")
done

json_data=$(IFS=, ; echo "${json_array[*]}")

# Create the JSON file
if [ ! -d "$target_directory" ]; then
    mkdir -p "$target_directory"
fi

echo "[$json_data]" > "$json_file"

echo "JSON file '$json_file' created with the following content:"
cat "$json_file"