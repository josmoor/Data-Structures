create: obscure.cpp circleObj.o rectObj.o
	g++ obscure.cpp -o obscure
circleObj.o: circleObj.h rectObj.o
	g++ -c circleObj.h
rectObj.o: rectObj.h
	g++ -c rectObj.h
clean:
	rm obscure
	rm rectObj.o
	rm circleObj.o
	rm rectData.txt
	rm angleObscureTotal.txt
run:
	./obscure
