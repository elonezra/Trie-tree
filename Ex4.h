#include <stdbool.h>
#include<string.h>

#ifndef _TRIE_H_
#define _TRIE_H_


#define WORD (int)30
#define LINE (int)255
#define CHAR_2_INDEX(letter) ((int)letter-(int)'a'); //return asci's value of letter
#define NUM_LETTERS (int)26
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0])) 

typedef enum {fls=0, tru=1} boolean;


typedef struct Node node;


node *getNode();
void insert(node *root, const char *word);
boolean search(node *root, const char *word);
int wordAmount(node *root, const char *word);
void display( node* root, char str[], int level);
void displayR( node* root, char str[], int level);

#endif




