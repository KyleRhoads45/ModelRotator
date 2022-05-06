CXX = g++
CFLAGS = -Wall -std=c++17
BUILD_DIR = ../build/
INCLUDE_DIR = -I ../include
LIBS = -L ../lib -lglfw3 -lgdi32

OBJECTS = $(addprefix $(BUILD_DIR), Main.o Glad.o Vector3.o Vector4.o Matrix4.o)

ModelRotator:	$(OBJECTS) 
	$(CXX) $(CFLAGS) $? -o $(BUILD_DIR)$@ $(INCLUDE_DIR) $(LIBS)

$(BUILD_DIR)Main.o:	main.cpp
	$(CXX) $(CFLAGS) -c $? -o $(BUILD_DIR)$@ $(INCLUDE_DIR)

$(BUILD_DIR)Glad.o:	../include/GLAD/glad.c
	$(CXX) $(CFLAGS) -c $? -o $(BUILD_DIR)$@ $(INCLUDE_DIR)

$(BUILD_DIR)Vector3.o:	Math/Vector3.cpp
	$(CXX) $(CFLAGS) -c $? -o $(BUILD_DIR)$@

$(BUILD_DIR)Vector4.o:	Math/Vector4.cpp
	$(CXX) $(CFLAGS) -c $? -o $(BUILD_DIR)$@

$(BUILD_DIR)Matrix4.o:	Math/Matrix4.cpp
	$(CXX) $(CFLAGS) -c $? -o $(BUILD_DIR)$@

clean:
	del ..\build\*.o
	del ..\build\*.exe