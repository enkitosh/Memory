all:
	gcc -o cache cache.c cache.h Ctables/Ctables.c Ctables/Ctables.h

clean: 
	rm -rf cache
