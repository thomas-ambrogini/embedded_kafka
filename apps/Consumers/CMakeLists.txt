add_executable(consumerOutputFile "${embedded_kafka_SOURCE_DIR}/apps/Consumers/consumerOutputFile.cpp")
target_link_libraries(consumerOutputFile PRIVATE application_library)

add_executable(watcher "${embedded_kafka_SOURCE_DIR}/apps/Consumers/watcher.cpp")
target_link_libraries(watcher PRIVATE application_library)
target_link_libraries(watcher PRIVATE pthread)

add_executable(processAndProduce "${embedded_kafka_SOURCE_DIR}/apps/Consumers/processAndProduce.cpp")
target_link_libraries(processAndProduce PRIVATE application_library)