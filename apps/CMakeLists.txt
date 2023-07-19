add_executable(configurer "${embedded_kafka_SOURCE_DIR}/apps/configurer.cpp")
target_link_libraries(configurer PRIVATE application_library)

add_executable(broker "${embedded_kafka_SOURCE_DIR}/apps/broker.cpp")
target_link_libraries(broker PRIVATE application_library)

add_executable(consumer "${embedded_kafka_SOURCE_DIR}/apps/consumer.cpp")
target_link_libraries(consumer PRIVATE application_library)

add_executable(producer "${embedded_kafka_SOURCE_DIR}/apps/producer.cpp")
target_link_libraries(producer PRIVATE application_library)
