create: main.cpp tree.o
	g++ main.cpp -o run
	./run
tree.o: tree.h
	g++ tree.h -o tree.o
clean:
	rm run
	rm *.o
	rm *.txt
exe:
	./run