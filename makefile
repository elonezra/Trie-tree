CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_LIB=Ex4.o
FLAGS= -Wall -g

all: trie_lib  frequency‬‬

frequency‬‬: $(OBJECTS_MAIN)  
	$(CC) $(FLAGS) -o ‫‪frequency‬‬ $(OBJECTS_MAIN) ./trie_lib.so

trie_lib: trie_lib.so

Ex4.o: Ex4.c Ex4.h
	$(CC) $(FLAG) -c Ex4.c 
	
trie_lib.so: $(OBJECTS_LIB) Ex4.h
	$(CC) -shared -o trie_lib.so $(OBJECTS_LIB)	



main.o: main.c Ex4.h
	$(CC) $(FLAG) -c main.c

.PHONY: clean all trie_lib frequency‬‬

clean:
	rm -f *.o *.a *.so progmains progmaind
