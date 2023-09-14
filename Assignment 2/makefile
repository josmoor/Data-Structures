create: obscure.cpp circleObj.o rectObj.o
	g++ obscure.cpp -o obscure
rectObj.o: rectObj.h
	g++ rectObj.h -o rectObj.o
circleObj.o: circleObj.h rectObj.o
	g++ circleObj.h -o circleObj.o
clean:
	rm *.o
	rm *.txt
run:
	./obscure
