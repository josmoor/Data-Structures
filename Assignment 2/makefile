create: obscure.cpp circleObj.o rectObj.o
	g++ obscure.cpp -o obscure
circleObj.o: circleObj.h rectObj.o
	g++ circleObj.h -o circleObj.o
rectObj.o: rectObj.h
	g++ rectObj.h -o rectObj.o
clean:
	rm obscure
	rm text.txt
	rm rectObj.o
	rm circleObj.o
	rm rectData.txt
	rm angleObscureTotal.txt
run:
	./obscure
