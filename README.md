# Embedded Kafka

## Table of Contents

- [Building](#building)
- [Usage](#usage)

## Building

Before proceeding, make sure you have the following tools and libraries installed on your system:

- CMake (minimum version 3.12): [Download CMake](https://cmake.org/download/)

### Build for A53 Linux

```bash
cd embedded_kafka
cmake -DCMAKE_TOOLCHAIN_FILE=toolchain-linux-arm.cmake -S . -B build_linux
cmake --build build_linux
```

### Build with CMake

```bash
cd embedded_kafka
cmake -S . -B build
cmake --build build
```

### Build with helping script

```bash
cd embedded_kafka
scripts/helping -b
```

## Usage

Every command assumes that you are in the project directory (embedded_kafka)

### Creates the config file with topics on it

```bash
scripts/helping -t Measurements Results
```

### Launch the Configurer and 2 brokers

```bash
scripts/helping -s 2
```

### Launch the producer

```bash
scripts/helping -p
```

### Launch the consumer

```bash
scripts/helping -c
```
