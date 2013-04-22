all: tests

EXEC = main testEx testTrans

tests: main.o testEx.o testTrans.o Ctables.o

main.o: main.c Ctables.c Ctables.h
	gcc -o main main.c Ctables.c Ctables.h

testEx.o: testEx.c Ctables.c Ctables.h
	gcc -o testEx testEx.c Ctables.c Ctables.h

testTrans.o: testTrans.c Ctables.c Ctables.h
	gcc -o testTrans testTrans.c Ctables.c Ctables.h

clean:
	rm -rf *o tests
	rm -rf $(EXEC)
