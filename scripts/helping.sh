#!/bin/bash

launch_script=false

usage() {
    echo "Usage: $0 [options]"
    echo "Options:"
    echo "  -h    Display this help message"    
    echo "  -b    Build the application"
    echo "  -t    Create the json file with the topics to manage"
    echo "  -s    Start system (configurer and brokers)"
    echo "  -p    Start producer"
    echo "  -c    Start consumer"
}

while getopts "hbts:pc" opt; do
    case "$opt" in
    h)
        usage
        exit 0
        ;;
    b)
        cmake -S .. -B ../build
        cmake --build ../build
        ;;
    t)
        # Shift the option index so that $1 refers to the first non-option argument
        shift $((OPTIND-1))
        scripts/create_topics_file.sh "$@"
        ;;
    s)
        nohup build/apps/configurer  >> build/output/configurer.txt &
        scripts/launch_brokers.sh $OPTARG
        ;;
    p)
        build/apps/producer
        ;;
    c)
        build/apps/consumer
        ;;
    \?)
        echo "Invalid option: -$OPTARG" >&2
        usage
        exit 1
        ;;
    esac
done
