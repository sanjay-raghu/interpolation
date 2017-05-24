output: main.o
	g++ -w main.o parent_grid.o child_grid.o grid_gen.o memory_allocation.o write_file.o get_value.o interpolate.o -o output.output

main.o: main.cpp memory_allocation.o parent_grid.o child_grid.o get_value.o write_file.o interpolate.o
	g++ -c main.cpp

parent_grid.o: parent_grid.cpp parent_grid.h grid_gen.o write_file.o
	g++ -c parent_grid.cpp

child_grid.o: child_grid.cpp child_grid.h grid_gen.o write_file.o
	g++ -c child_grid.cpp

grid_gen.o: grid_gen.cpp grid_gen.h
	g++ -c grid_gen.cpp

memory_allocation.o: memory_allocation.cpp memory_allocation.h
	g++ -c memory_allocation.cpp

write_file.o: write_file.cpp write_file.h
	g++ -c write_file.cpp

get_value.o: get_value.cpp get_value.h
	g++ -c get_value.cpp

interpolate.o: interpolate.cpp interpolate.h
	g++ -c interpolate.cpp
clean:
	rm -f *.o *.out
