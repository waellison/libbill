CFLAGS = -Wall -Wextra -pedantic -std=c99 -g -I../include \
         -DGL_GLEXT_PROTOTYPES

all: libbill.a

OBJS = libbill.o text_file_preprocess.o compare.o clamp.o vectormath.o \
       uniform_ops.o text_file_read.o bstring.o

docs:
	doxygen Doxyfile

libbill.a: $(OBJS)
	ar ru libbill.a $(OBJS)
	ranlib libbill.a 
	cp libbill.a ../..

clean:
	rm -f core *.o libbill.a

.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) -c $*.c

