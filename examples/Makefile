CLANG=clang++-6.0
STD=-std=c++17
FLAGS=-Werror

LINK_OPENGL=-lGLEW -lGL -lGLU -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -lXi -ldl -lXinerama -lXcursor

example1: example1.cpp
	$(CLANG) $(STD) $< -o $@ $(LINK_OPENGL)

example2: example2.cpp
	$(CLANG) $(STD) $< -o $@ $(LINK_OPENGL)

run1:
	./example1

run2:
	./example2

clean:
	rm -rf *.o example1 example2
