sum-nbo: sum-nbo.o 
	gcc -o sum-nbo sum-nbo.o

sum-nbo.o: sum-nbo.cpp
	gcc -c -o sum-nbo.o sum-nbo.cpp

clean:
	rm -f *.o sum-nbo *.bin
