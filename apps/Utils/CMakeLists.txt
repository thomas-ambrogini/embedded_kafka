add_executable(launchMessage "${embedded_kafka_SOURCE_DIR}/apps/Utils/launchMessage.cpp")
target_link_libraries(launchMessage PRIVATE application_library)

add_executable(directCommunicationTesting "${embedded_kafka_SOURCE_DIR}/apps/Utils/directCommunicationTesting.cpp")
target_link_libraries(directCommunicationTesting PRIVATE application_library)
