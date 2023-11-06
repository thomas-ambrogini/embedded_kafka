add_executable(periodicProducer "${embedded_kafka_SOURCE_DIR}/apps/Producers/periodicProducer.cpp")
target_link_libraries(periodicProducer PRIVATE application_library)

add_executable(linuxProducerBrokerRTOS "${embedded_kafka_SOURCE_DIR}/apps/Producers/linuxProducerBrokerRTOS.cpp")
target_link_libraries(linuxProducerBrokerRTOS PRIVATE application_library)