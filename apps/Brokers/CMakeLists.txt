add_executable(brokerPC "${embedded_kafka_SOURCE_DIR}/apps/Brokers/brokerPC.cpp")
target_link_libraries(brokerPC PRIVATE application_library)