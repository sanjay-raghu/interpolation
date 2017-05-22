output: main.o parent_grid.o  grid_gen.o get_value.o  Bilinerinterpolate.o memory_allocation_2d.o
	g++ -w main.o parent_grid.o  grid_gen.o get_value.o Bilinerinterpolate.o  memory_allocation_2d.o -o output.out

main.o: main.cpp parent_grid.cpp grid_gen.cpp get_value.cpp Bilinerinterpolate.cpp  grid_gen.h parent_grid.h get_value.h amrsolver.h
	g++ -c main.cpp

parent_grid.o: parent_grid.cpp parent_grid.h grid_gen.h
	g++ -c parent_grid.cpp

child_grid.o: child_grid.cpp grid_gen.cpp get_A_matrix.cpp child_grid.h grid_gen.h get_A_matrix.h
	g++ -c child_grid.cpp
get_value.o: get_value.cpp
	g++ -c get_value.cpp

grid_gen.o: grid_gen.cpp
	g++ -c grid_gen.cpp

get_A_matrix.o: get_A_matrix.cpp interpolation.cpp get_A_matrix.h interpolation.h
	g++ -c get_A_matrix.cpp

interpolation.o: interpolation.cpp interpolation.h
	g++ -c interpolation.cpp

memory_allocation_2d.o: memory_allocation_2d.cpp memory_allocation_2d.h
	g++ -c memory_allocation_2d.cpp
Bilinerinterpolate.o: Bilinerinterpolate.cpp 
	g++ -c Bilinerinterpolate.cpp




clean:
	rm -f *.o *.out
