CFLAGS = -Wall -fpic -coverage -lm -std=c99

testme.o: testme.c
	gcc -c testme.c -g  $(CFLAGS)

runtests: testme.c
	echo "Results for testme.c" > randomtests.out
	gcc -o testme testme.c $(CFLAGS)
	gcov testme.c -b >> randomtests.out

clean:
	rm -f *.o *.out *.gcov *.gcda *.gcno *.so 