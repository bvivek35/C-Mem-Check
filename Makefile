all : obj/test.o lib/libdetect.a 
	if [ ! -d "bin" ]; then mkdir -p bin; fi
	gcc obj/test.o -Llib -o bin/test -ldetect

obj/my_list.o : src/my_list.c
	if [ ! -d "obj" ]; then mkdir -p obj; fi
	gcc -c src/my_list.c -Iinclude -o obj/my_list.o

obj/my_mem_check.o : src/my_mem_check.c
	if [ ! -d "obj" ]; then mkdir -p obj; fi
	gcc -c 	src/my_mem_check.c -Iinclude -o obj/my_mem_check.o

obj/test.o : tst/test.c
	if [ ! -d "obj" ]; then mkdir -p obj; fi
	gcc -c tst/test.c -Iinclude -o obj/test.o -Dmalloc=my_malloc -Dfree=my_free

lib/libdetect.a : obj/my_list.o obj/my_mem_check.o
	if [ ! -d "lib" ]; then mkdir -p lib; fi
	ar rcs lib/libdetect.a obj/my_list.o obj/my_mem_check.o

clean : 
	rm -f */*.o bin/* lib/*
