all:
	gcc -o memory memory.c memory.h Ctables/Ctables.c Ctables/Ctables.h

clean: 
	rm -rf memory
