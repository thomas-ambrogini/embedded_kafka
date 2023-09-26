add_executable(periodicProducer "${embedded_kafka_SOURCE_DIR}/apps/Producers/periodicProducer.cpp")
target_link_libraries(periodicProducer PRIVATE application_library)