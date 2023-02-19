
# Binaries
GCC     = gcc
G++     = g++
OBJCOPY = objcopy
OBJDUMP = objdump

## The name of your project (without the .c)
## Name it automatically after the enclosing directory
TARGET = $(lastword $(subst /, ,$(CURDIR)))

ROOT = .

BUILD_DIR = $(ROOT)/build

LIB_DIRS = 

C_SOURCES = $(foreach dir, $(LIB_DIRS), $(wildcard $(dir)*.c)) $(wildcard *.c)
CPP_SOURCES = $(foreach dir, $(LIB_DIRS), $(wildcard $(dir)*.cpp)) $(wildcard *.cpp)

SOURCES = $(CPP_SOURCES) $(C_SOURCES) $(ASM_SOURCES)

OBJECTS = \
	$(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o))) \
	$(addprefix $(BUILD_DIR)/,$(notdir $(CPP_SOURCES:.cpp=.o))) \

vpath %.cpp $(sort $(dir $(CPP_SOURCES)))
vpath %.c $(sort $(dir $(C_SOURCES)))
	
INC = $(addprefix -I, $(LIB_DIRS))

CFLAGS += $(INC)
CFLAGS += -O0
CFLAGS += -std=gnu11
CFLAGS += -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
CFLAGS += -Wall -Wstrict-prototypes

LDFLAGS = -Wl,-Map,$(BUILD_DIR)/$(TARGET).map 
## Optional, but often ends up with smaller code
LDFLAGS += -Wl,--gc-sections


$(BUILD_DIR):
	mkdir $@

$(BUILD_DIR)/%.o : %.cpp $(BUILD_DIR)
	$(G++) $< $(CPPFLAGS) -c -o $@

$(BUILD_DIR)/%.o : %.c $(BUILD_DIR)
	$(GCC) $< $(CFLAGS) -c -o $@

$(BUILD_DIR)/$(TARGET): $(OBJECTS)
	$(GCC) $(LDFLAGS) $^ -o $@


## These targets don't have files named after them
.PHONY: all debug clean

all: $(BUILD_DIR)/$(TARGET)

debug:
	@echo
	@echo "Target: $(TARGET)"
	@echo "CPP Source files: $(CPP_SOURCES)"
	@echo "C Source files: $(C_SOURCES)"
	@echo "Build dir: $(BUILD_DIR)"
	@echo "Source files: $(SOURCES)"
	@echo "Object files: $(OBJECTS)"
	@echo

clean:
	rm -rf $(BUILD_DIR)
