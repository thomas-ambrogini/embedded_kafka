# CMAKE generated file: DO NOT EDIT!
# Generated by CMake Version 3.26
cmake_policy(SET CMP0009 NEW)

# SOURCES_TI_RPMSG_CHAR_LIST at external/ti_rpmsg_char/CMakeLists.txt:2 (file)
file(GLOB NEW_GLOB LIST_DIRECTORIES true "/home/thomas/embedded_kafka/external/ti_rpmsg_char/*.c")
set(OLD_GLOB
  "/home/thomas/embedded_kafka/external/ti_rpmsg_char/rpmsg_char.c"
  "/home/thomas/embedded_kafka/external/ti_rpmsg_char/soc.c"
  "/home/thomas/embedded_kafka/external/ti_rpmsg_char/utils.c"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/home/thomas/embedded_kafka/build_linux/CMakeFiles/cmake.verify_globs")
endif()

# HEADER_TI_RPMSG_CHAR_LIST at external/ti_rpmsg_char/CMakeLists.txt:1 (file)
file(GLOB NEW_GLOB LIST_DIRECTORIES true "/home/thomas/embedded_kafka/external/ti_rpmsg_char/include/*.h")
set(OLD_GLOB
  "/home/thomas/embedded_kafka/external/ti_rpmsg_char/include/rpmsg_char_internal.h"
  "/home/thomas/embedded_kafka/external/ti_rpmsg_char/include/rproc_id.h"
  "/home/thomas/embedded_kafka/external/ti_rpmsg_char/include/ti_rpmsg_char.h"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/home/thomas/embedded_kafka/build_linux/CMakeFiles/cmake.verify_globs")
endif()

# HEADER_APPLICATION_LIST at src/Application/CMakeLists.txt:1 (file)
file(GLOB NEW_GLOB LIST_DIRECTORIES true "/home/thomas/embedded_kafka/include/Application/*.hpp")
set(OLD_GLOB
  "/home/thomas/embedded_kafka/include/Application/Broker.hpp"
  "/home/thomas/embedded_kafka/include/Application/Configurer.hpp"
  "/home/thomas/embedded_kafka/include/Application/Consumer.hpp"
  "/home/thomas/embedded_kafka/include/Application/Producer.hpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/home/thomas/embedded_kafka/build_linux/CMakeFiles/cmake.verify_globs")
endif()

# HEADER_COMMUNICATION_LIST at src/Communication/CMakeLists.txt:1 (file)
file(GLOB NEW_GLOB LIST_DIRECTORIES true "/home/thomas/embedded_kafka/include/Communication/*.hpp")
set(OLD_GLOB
  "/home/thomas/embedded_kafka/include/Communication/Communication.hpp"
  "/home/thomas/embedded_kafka/include/Communication/CommunicationFactory.hpp"
  "/home/thomas/embedded_kafka/include/Communication/CommunicationUtils.hpp"
  "/home/thomas/embedded_kafka/include/Communication/IPCNotifyCommunication.hpp"
  "/home/thomas/embedded_kafka/include/Communication/RPMessageCommunication.hpp"
  "/home/thomas/embedded_kafka/include/Communication/RPMessageLinuxCommunication.hpp"
  "/home/thomas/embedded_kafka/include/Communication/UDPSocketCommunication.hpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/home/thomas/embedded_kafka/build_linux/CMakeFiles/cmake.verify_globs")
endif()

# HEADER_DIAGNOSTIC_LIST at src/Diagnostic/CMakeLists.txt:1 (file)
file(GLOB NEW_GLOB LIST_DIRECTORIES true "/home/thomas/embedded_kafka/include/Diagnostic/*.hpp")
set(OLD_GLOB
  "/home/thomas/embedded_kafka/include/Diagnostic/Diagnostic.hpp"
  "/home/thomas/embedded_kafka/include/Diagnostic/LatencyDiagnostic.hpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/home/thomas/embedded_kafka/build_linux/CMakeFiles/cmake.verify_globs")
endif()

# HEADER_DOMAIN_LIST at src/Domain/CMakeLists.txt:1 (file)
file(GLOB NEW_GLOB LIST_DIRECTORIES true "/home/thomas/embedded_kafka/include/Domain/*.hpp")
set(OLD_GLOB
  "/home/thomas/embedded_kafka/include/Domain/BrokerMetadata.hpp"
  "/home/thomas/embedded_kafka/include/Domain/ClusterMetadata.hpp"
  "/home/thomas/embedded_kafka/include/Domain/CommunicationFactory.hpp"
  "/home/thomas/embedded_kafka/include/Domain/CommunicationType.hpp"
  "/home/thomas/embedded_kafka/include/Domain/ConsumerMetadata.hpp"
  "/home/thomas/embedded_kafka/include/Domain/Endpoint.hpp"
  "/home/thomas/embedded_kafka/include/Domain/EndpointFactory.hpp"
  "/home/thomas/embedded_kafka/include/Domain/IPCNotifyEndpoint.hpp"
  "/home/thomas/embedded_kafka/include/Domain/Processor.hpp"
  "/home/thomas/embedded_kafka/include/Domain/ProducerMetadata.hpp"
  "/home/thomas/embedded_kafka/include/Domain/RPMessageEndpoint.hpp"
  "/home/thomas/embedded_kafka/include/Domain/TopicMetadata.hpp"
  "/home/thomas/embedded_kafka/include/Domain/UDPEndpoint.hpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/home/thomas/embedded_kafka/build_linux/CMakeFiles/cmake.verify_globs")
endif()

# HEADER_TOPICMANAGER_LIST at src/TopicManager/CMakeLists.txt:1 (file)
file(GLOB NEW_GLOB LIST_DIRECTORIES true "/home/thomas/embedded_kafka/include/TopicManager/*.hpp")
set(OLD_GLOB
  "/home/thomas/embedded_kafka/include/TopicManager/ProducerRecord.hpp"
  "/home/thomas/embedded_kafka/include/TopicManager/RealTopic.hpp"
  "/home/thomas/embedded_kafka/include/TopicManager/Record.hpp"
  "/home/thomas/embedded_kafka/include/TopicManager/SystemManager.hpp"
  "/home/thomas/embedded_kafka/include/TopicManager/Topic.hpp"
  "/home/thomas/embedded_kafka/include/TopicManager/TopicFactory.hpp"
  "/home/thomas/embedded_kafka/include/TopicManager/TopicHandler.hpp"
  "/home/thomas/embedded_kafka/include/TopicManager/TopicProxy.hpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/home/thomas/embedded_kafka/build_linux/CMakeFiles/cmake.verify_globs")
endif()

# HEADER_UTILS_LIST at src/utils/CMakeLists.txt:1 (file)
file(GLOB NEW_GLOB LIST_DIRECTORIES true "/home/thomas/embedded_kafka/include/utils/*.hpp")
set(OLD_GLOB
  "/home/thomas/embedded_kafka/include/utils/JsonUtils.hpp"
  "/home/thomas/embedded_kafka/include/utils/Logger.hpp"
  "/home/thomas/embedded_kafka/include/utils/StandardOutputLogger.hpp"
  "/home/thomas/embedded_kafka/include/utils/TI_DebugLogger.hpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/home/thomas/embedded_kafka/build_linux/CMakeFiles/cmake.verify_globs")
endif()

# SOURCES_APPLICATION_LIST at src/Application/CMakeLists.txt:2 (file)
file(GLOB NEW_GLOB LIST_DIRECTORIES true "/home/thomas/embedded_kafka/src/Application/*.cpp")
set(OLD_GLOB
  "/home/thomas/embedded_kafka/src/Application/Broker.cpp"
  "/home/thomas/embedded_kafka/src/Application/Configurer.cpp"
  "/home/thomas/embedded_kafka/src/Application/Consumer.cpp"
  "/home/thomas/embedded_kafka/src/Application/Producer.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/home/thomas/embedded_kafka/build_linux/CMakeFiles/cmake.verify_globs")
endif()

# SOURCES_COMMUNICATION_LIST at src/Communication/CMakeLists.txt:2 (file)
file(GLOB NEW_GLOB LIST_DIRECTORIES true "/home/thomas/embedded_kafka/src/Communication/*.cpp")
set(OLD_GLOB
  "/home/thomas/embedded_kafka/src/Communication/CommunicationFactory.cpp"
  "/home/thomas/embedded_kafka/src/Communication/CommunicationUtils.cpp"
  "/home/thomas/embedded_kafka/src/Communication/IPCNotifyCommunication.cpp"
  "/home/thomas/embedded_kafka/src/Communication/RPMessageCommunication.cpp"
  "/home/thomas/embedded_kafka/src/Communication/RPMessageLinuxCommunication.cpp"
  "/home/thomas/embedded_kafka/src/Communication/UDPSocketCommunication.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/home/thomas/embedded_kafka/build_linux/CMakeFiles/cmake.verify_globs")
endif()

# SOURCES_DIAGNOSTIC_LIST at src/Diagnostic/CMakeLists.txt:2 (file)
file(GLOB NEW_GLOB LIST_DIRECTORIES true "/home/thomas/embedded_kafka/src/Diagnostic/*.cpp")
set(OLD_GLOB
  "/home/thomas/embedded_kafka/src/Diagnostic/LatencyDiagnostic.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/home/thomas/embedded_kafka/build_linux/CMakeFiles/cmake.verify_globs")
endif()

# SOURCES_DOMAIN_LIST at src/Domain/CMakeLists.txt:2 (file)
file(GLOB NEW_GLOB LIST_DIRECTORIES true "/home/thomas/embedded_kafka/src/Domain/*.cpp")
set(OLD_GLOB
  "/home/thomas/embedded_kafka/src/Domain/BrokerMetadata.cpp"
  "/home/thomas/embedded_kafka/src/Domain/ClusterMetadata.cpp"
  "/home/thomas/embedded_kafka/src/Domain/ConsumerMetadata.cpp"
  "/home/thomas/embedded_kafka/src/Domain/EndpointFactory.cpp"
  "/home/thomas/embedded_kafka/src/Domain/IPCNotifyEndpoint.cpp"
  "/home/thomas/embedded_kafka/src/Domain/ProducerMetadata.cpp"
  "/home/thomas/embedded_kafka/src/Domain/RPMessageEndpoint.cpp"
  "/home/thomas/embedded_kafka/src/Domain/TopicMetadata.cpp"
  "/home/thomas/embedded_kafka/src/Domain/UDPEndpoint.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/home/thomas/embedded_kafka/build_linux/CMakeFiles/cmake.verify_globs")
endif()

# SOURCES_TOPICMANAGER_LIST at src/TopicManager/CMakeLists.txt:2 (file)
file(GLOB NEW_GLOB LIST_DIRECTORIES true "/home/thomas/embedded_kafka/src/TopicManager/*.cpp")
set(OLD_GLOB
  "/home/thomas/embedded_kafka/src/TopicManager/ProducerRecord.cpp"
  "/home/thomas/embedded_kafka/src/TopicManager/RealTopic.cpp"
  "/home/thomas/embedded_kafka/src/TopicManager/Record.cpp"
  "/home/thomas/embedded_kafka/src/TopicManager/SystemManager.cpp"
  "/home/thomas/embedded_kafka/src/TopicManager/Topic.cpp"
  "/home/thomas/embedded_kafka/src/TopicManager/TopicFactory.cpp"
  "/home/thomas/embedded_kafka/src/TopicManager/TopicHandler.cpp"
  "/home/thomas/embedded_kafka/src/TopicManager/TopicProxy.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/home/thomas/embedded_kafka/build_linux/CMakeFiles/cmake.verify_globs")
endif()

# SOURCES_UTILS_LIST at src/utils/CMakeLists.txt:2 (file)
file(GLOB NEW_GLOB LIST_DIRECTORIES true "/home/thomas/embedded_kafka/src/utils/*.cpp")
set(OLD_GLOB
  "/home/thomas/embedded_kafka/src/utils/JsonUtils.cpp"
  "/home/thomas/embedded_kafka/src/utils/StandardOutputLogger.cpp"
  "/home/thomas/embedded_kafka/src/utils/TI_DebugLogger.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/home/thomas/embedded_kafka/build_linux/CMakeFiles/cmake.verify_globs")
endif()