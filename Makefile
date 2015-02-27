CC := gcc

LIB_SRCDIR := src
LIB_OBJDIR := obj
LIBDIR := lib

INCL := -Iinclude/
CFLAGS := 
DEFINES :=


LIB_SRCS := $(wildcard src/*.c)
LIB_OBJS := $(subst src, obj, $(LIB_SRCS))
LIB_OBJS := $(patsubst %.c, %.o, $(LIB_OBJS))

LIB := libdetect.a 

test1 : tst/test1.c lib
	$(CC) $(INCL) -DHOOK_ALL $(CFLAGS) tst/test1.c -L$(LIBDIR) -o bin/test1 -ldetect

lib : $(LIB_OBJS)
	ar rcs $(LIBDIR)/$(LIB) $^
 
$(LIB_OBJDIR)/%.o : $(LIB_SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INCL) -c $< -o $@  

clean : 
	rm -rf bin/* obj/* lib/* a.out *.o
