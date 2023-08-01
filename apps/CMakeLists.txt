add_executable(configurerLinux "${embedded_kafka_SOURCE_DIR}/apps/configurerLinux.cpp")
target_link_libraries(configurerLinux PRIVATE application_library)

add_executable(printer "${embedded_kafka_SOURCE_DIR}/apps/printerService.cpp")
target_link_libraries(printer PRIVATE application_library)

add_executable(broker "${embedded_kafka_SOURCE_DIR}/apps/broker.cpp")
target_link_libraries(broker PRIVATE application_library)

add_executable(consumer "${embedded_kafka_SOURCE_DIR}/apps/consumer.cpp")
target_link_libraries(consumer PRIVATE application_library)

add_executable(producer "${embedded_kafka_SOURCE_DIR}/apps/producer.cpp")
target_link_libraries(producer PRIVATE application_library)

add_executable(linux_direct_communication_test "${embedded_kafka_SOURCE_DIR}/apps/rpmsg_char_simple.cpp")
target_link_libraries(linux_direct_communication_test PRIVATE application_library)
