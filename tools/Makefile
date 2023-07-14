export BASE_DIRECTORY?=$(abspath ../)

CXX      := aarch64-none-linux-gnu-gcc
CXXFLAGS := -Wall -Wextra -pthread
WERROR   := -Werror
LDFLAGS  := -L/usr/lib -lstdc++ -lm

BUILD    := ../build
OBJ_DIR  := $(BUILD)/objects
SRC_DIR  := ../src
LIB_DIR  := ../lib
APP_DIR  := $(BUILD)/apps

LIB_INCDIRS := $(shell find $(LIB_DIR) -type d -name 'interfaces')
INCLUDES := $(patsubst %,-I%,$(LIB_INCDIRS))

LIB_SRC := $(shell find $(LIB_DIR) -type f -name '*.cpp')
LIB_OBJ := $(patsubst $(LIB_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(LIB_SRC))

LIB_SRC_C := $(shell find $(LIB_DIR) -type f -name '*.c')
LIB_OBJ += $(patsubst $(LIB_DIR)/%.c,$(OBJ_DIR)/%.o,$(LIB_SRC_C))

MAIN_SRC := $(shell find $(SRC_DIR) -type f -name '*.cpp')
MAIN_OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(MAIN_SRC))


all: build broker configurer producer consumer

print:
	@echo $(LIB_SRC_C)

# Rule to compile lib source files into object files
$(OBJ_DIR)/%.o: $(LIB_DIR)/%.c
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Rule to compile rpmsg.c and client.cpp into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Rule to compile broker.cpp, server.cpp, configurer.cpp and client.cpp into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Rule to compile lib source files into object files
$(OBJ_DIR)/%.o: $(LIB_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: all build clean debug release info

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

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

rpmsg: $(OBJ_DIR)/rpmsg_char_simple.o $(LIB_OBJ)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(APP_DIR)/rpmsg_char_simple $^ $(LDFLAGS)

scripts: $(OBJ_DIR)/createBrokers.o $(LIB_OBJ)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(APP_DIR)/createBrokers $^ $(LDFLAGS)

clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(APP_DIR)/*
	