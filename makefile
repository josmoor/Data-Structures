create: main.cpp queen.o
	g++ main.cpp -o run
queen.o: queen.h
	g++ queen.h -o queen.o
clean:
	rm *.o
	rm *.txt
run:
	./run
