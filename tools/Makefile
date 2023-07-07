export BASE_DIRECTORY?=$(abspath ../)

CXX      := g++
CXXFLAGS := -pedantic-errors -Wall -Wextra -Werror -pthread
LDFLAGS  := -L/usr/lib -lstdc++ -lm

BUILD    := ../build
OBJ_DIR  := $(BUILD)/objects
SRC_DIR  := ../src
LIB_DIR  := ../lib
APP_DIR  := $(BUILD)/apps
TARGET   := main

SERVER = socket_server.o
BROKER = ../build/objects/broker.o


# Find all middleware header directories recursively
LIB_INCDIRS := $(shell find $(LIB_DIR) -type d -name 'interfaces')
# Generate include flags for each middleware header directory
INCLUDES := $(patsubst %,-I%,$(LIB_INCDIRS))


#Find all SRCS of the lib
LIB_SRC := $(shell find $(LIB_DIR) -type f -name '*.cpp')
#Make all the SRCS objects
LIB_OBJ := $(patsubst $(LIB_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(LIB_SRC))

MAIN_SRC := \
   $(wildcard $(SRC_DIR)/*.cpp)

MAIN_OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(MAIN_SRC))


OBJECTS  := $(SRC:%.cpp=$(OBJ_DIR)/%.o)

MAIN_OBJECTS := $(MAIN_SRC:%.cpp=$(OBJ_DIR)/%.o)

print_main_objects:
	@echo $(INCLUDES)

DEPENDENCIES := \
        $(OBJECTS:.o=.d)

all: build broker configurer producer consumer

$(OBJ_DIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -MMD -o $@


$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $(APP_DIR)/$(TARGET) $^ $(LDFLAGS)

-include $(DEPENDENCIES)

.PHONY: all build clean debug release info

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

server:
	$(CXX) $(CXXFLAGS) -o $(APP_DIR)/socket_server $(SERVER) $(LDFLAGS)


broker: $(OBJ_DIR)/broker.o $(LIB_OBJ)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(APP_DIR)/broker $^ $(LDFLAGS)

configurer: $(OBJ_DIR)/configurer.o $(LIB_OBJ)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(APP_DIR)/configurer $^ $(LDFLAGS)

producer: $(OBJ_DIR)/producer.o $(LIB_OBJ)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(APP_DIR)/producer $^ $(LDFLAGS)

consumer: $(OBJ_DIR)/consumer.o $(LIB_OBJ)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(APP_DIR)/consumer $^ $(LDFLAGS)

prova: $(OBJ_DIR)/prova.o $(LIB_OBJ)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(APP_DIR)/prova $^ $(LDFLAGS)

# Rule to compile broker.cpp, server.cpp, configurer.cpp and client.cpp into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Rule to compile lib source files into object files
$(OBJ_DIR)/%.o: $(LIB_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@
debug: CXXFLAGS += -DDEBUG -g
debug: all

release: CXXFLAGS += -O2
release: all

clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(APP_DIR)/*

info:
	@echo "[*] Application dir: ${APP_DIR}     "
	@echo "[*] Object dir:      ${OBJ_DIR}     "
	@echo "[*] Sources:         ${SRC}         "
	@echo "[*] Objects:         ${OBJECTS}     "
	@echo "[*] Dependencies:    ${DEPENDENCIES}"