CC = g++
CFLAGS = -Wall -std=c++17
INCLUDE_DIR = -I ../include
LIBS = -L ../lib -lglfw3 -lgdi32

#external source files
GLAD = ../include/GLAD/glad.c

ModelRotator:	main.cpp Matrix4.cpp Vector4.cpp $(GLAD) 
	$(CC) $(CFLAGS) $? -o $@ $(INCLUDE_DIR) $(LIBS)