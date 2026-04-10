# Name of final executable
program: genome.o main.o
	g++ genome.o main.o -o program

# Compile genome.cpp into genome.o
genome.o: genome.cpp genome.h
	g++ -c genome.cpp

# Compile main.cpp into main.o
main.o: main.cpp genome.h
	g++ -c main.cpp

# Clean up generated files
clean:
	rm -f *.o program