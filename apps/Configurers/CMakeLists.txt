add_executable(configurerLinux "${embedded_kafka_SOURCE_DIR}/apps/Configurers/configurerLinux.cpp")
target_link_libraries(configurerLinux PRIVATE application_library)

add_executable(configurerPC "${embedded_kafka_SOURCE_DIR}/apps/Configurers/configurerPC.cpp")
target_link_libraries(configurerPC PRIVATE application_library)