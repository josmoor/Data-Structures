create: obscure.cpp circleObj.o rectObj.o
	g++ obscure.cpp -o obscure
circleObj.o: circleObj.h rectObj.o
	g++ circleObj.h -o circleObj.o
rectObj.o: rectObj.h
	g++ rectObj.h -o rectObj.o
clean:
	rm *.txt
	rm *.o
run:
	./obscure
