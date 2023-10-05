add_executable(launchMessage "${embedded_kafka_SOURCE_DIR}/apps/Utils/launchMessage.cpp")
target_link_libraries(launchMessage PRIVATE application_library)
