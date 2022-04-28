prog:Main.o Songify.o Artist.o Album.o Song.o
	gcc Main.o Songify.o Artist.o Album.o Song.o -o prog
Main.o:Main.c Structs.h Songify.h Artist.h Album.h Song.h
	gcc -c Main.c
Songify.o:Songify.c Songify.h Structs.h
	gcc -c Songify.c
Artist.o:Artist.c Artist.h Structs.h
	gcc -c Artist.c
Album.o:Album.c Album.h Structs.h
	gcc -c Album.c
Song.o:Song.c Song.h Structs.h
	gcc -c Song.c