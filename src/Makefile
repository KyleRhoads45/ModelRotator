CXX = g++
CPPFLAGS = -Wall -std=c++17 -fopenmp -o3
INCLUDE_DIR = -I ../include
LIBS = -L ../lib -lglfw3 -lgdi32 -fopenmp
OBJECT_DIR = ./objects/

OBJECTS = $(addprefix $(OBJECT_DIR), Glad.o Mesh.o Shader.o Vertex.o Timer.o Vector2.o Vector3.o Vector4.o Matrix4.o)

all: ModelRotatorParallel ModelRotatorSequential

ModelRotatorParallel:	$(OBJECT_DIR)MainOMP.o $(OBJECTS) 
	$(CXX) $(CPPFLAGS) $? -o $@ $(INCLUDE_DIR) $(LIBS)

ModelRotatorSequential:	$(OBJECT_DIR)MainSeq.o $(OBJECTS) 
	$(CXX) $(CPPFLAGS) $? -o $@ $(INCLUDE_DIR) $(LIBS)

$(OBJECT_DIR)MainOMP.o:	main.cpp
	$(CXX) $(CPPFLAGS) -c $? -o $@ $(INCLUDE_DIR) -D OPEN_MP

$(OBJECT_DIR)MainSeq.o:	main.cpp
	$(CXX) $(CPPFLAGS) -c $? -o $@ $(INCLUDE_DIR)

$(OBJECT_DIR)Glad.o:	../include/GLAD/glad.c
	$(CXX) $(CPPFLAGS) -c $? -o $@ $(INCLUDE_DIR)

$(OBJECT_DIR)Mesh.o:	Mesh.cpp
	$(CXX) $(CPPFLAGS) -c $? -o $@ $(INCLUDE_DIR)

$(OBJECT_DIR)Shader.o:	Shader.cpp
	$(CXX) $(CPPFLAGS) -c $? -o $@ $(INCLUDE_DIR)

$(OBJECT_DIR)Vertex.o:	Vertex.cpp
	$(CXX) $(CPPFLAGS) -c $? -o $@ $(INCLUDE_DIR)

$(OBJECT_DIR)Timer.o:	Timer.cpp
	$(CXX) $(CPPFLAGS) -c $? -o $@ $(INCLUDE_DIR)

$(OBJECT_DIR)Vector2.o:	math/Vector2.cpp
	$(CXX) $(CPPFLAGS) -c $? -o $@

$(OBJECT_DIR)Vector3.o:	math/Vector3.cpp
	$(CXX) $(CPPFLAGS) -c $? -o $@

$(OBJECT_DIR)Vector4.o:	math/Vector4.cpp
	$(CXX) $(CPPFLAGS) -c $? -o $@

$(OBJECT_DIR)Matrix4.o:	math/Matrix4.cpp
	$(CXX) $(CPPFLAGS) -c $? -o $@

clean:
	del .\objects\*.o
	del *.exe