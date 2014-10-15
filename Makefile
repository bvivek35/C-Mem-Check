all : obj/test.o lib/libdetect.a 
	gcc obj/test.o -Llib -o bin/test -ldetect

obj/my_list.o : src/my_list.c
	gcc -c src/my_list.c -Iinclude -o obj/my_list.o

obj/my_mem_check.o : src/my_mem_check.c
	gcc -c 	src/my_mem_check.c -Iinclude -o obj/my_mem_check.o

obj/test.o : tst/test.c
	gcc -c tst/test.c -Iinclude -o obj/test.o -Dmalloc=my_malloc -Dfree=my_free

lib/libdetect.a : obj/my_list.o obj/my_mem_check.o
	ar rcs lib/libdetect.a obj/my_list.o obj/my_mem_check.o

clean : 
	rm -f */*.o bin/* lib/*
