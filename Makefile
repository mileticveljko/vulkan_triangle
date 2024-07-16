# Variables
CXX = g++
SRC =   ./src/main.cpp \
        ./src/v_core.cpp \
	    ./src/v_instance.cpp \
		./src/v_validation_layer.cpp
		
OUTPUT = vulkan_triangle_tut
CFLAGS = -std=c++20 -g -O0 -Wall -Wextra -pedantic
LDFLAGS = -lglfw -lvulkan
DEFINES = -DDEBUG

# Create bin folder and compile
all: $(OUTPUT)

$(OUTPUT): $(SRC)
	mkdir -p bin
	$(CXX) $(SRC) $(CFLAGS) $(LDFLAGS) $(DEFINES) -o bin/$(OUTPUT)

clean:
	rm -rf bin