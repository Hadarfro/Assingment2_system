CC = gcc
AR = ar
CFLAGS = -Wall -g
AFLAGS = rcs

.PHONY: all clean 

all: connections

connections: my_graph.o libMy_mat.a
	$(CC) $(CFLAGS) -c my_graph.o libMy_mat.a -o connections
	       
libMy_mat.a: my_mat.o   
	$(AR) $(AFLAGS) libMy_mat.a my_mat.o

my_mat.o: my_mat.c my_mat.h
	$(CC) $(CFLAGS) -c my_mat.c 

my_graph.o: my_graph.c my_mat.h 
	$(CC) $(CFLAGS) -c my_graph.c 

my_Knapsack.o: my_Knapsack.c my_mat.h 
	$(CC) $(CFLAGS) -c my_Knapsack.c 

clean:
	rm -f *.o *.a connections
