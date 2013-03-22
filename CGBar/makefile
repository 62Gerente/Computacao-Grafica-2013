primitivas: main.cpp sphere.o cylinder.o cube.o plane.o
	gcc -o primitivas main.cpp sphere.o cylinder.o cube.o plane.o -framework GLUT -framework OpenGL -framework GLKit

sphere.o: sphere/sphere.cpp
	gcc -c sphere/sphere.cpp 

cylinder.o: cylinder/cylinder.cpp
	gcc -c cylinder/cylinder.cpp

cube.o: cube/cube.cpp
	gcc -c cube/cube.cpp

plane.o: plane/plane.cpp
	gcc -c plane/plane.cpp 

clear:
	rm *.o
	rm primitivas

exec: primitivas
	./primitivas
