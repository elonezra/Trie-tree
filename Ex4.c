#include <stdio.h>

#define CHAR_2_INDEX(letter) ((int)letter-(int)'a'); //return asci's value of letter
#define NUM_LETTERS (int)26

typedef enum {false=0, true=1} boolean;

typedef struct Node { 
int count;
char letter;
struct node * next_child[NUM_LETTERS];
boolean endOfWord ;
} node;


node *getNode(void) 
{ 
    node *pNode = NULL; 
    pNode->count = 0;
    pNode = ( node *)malloc(sizeof(node)); 
  
    if (pNode) 
    { 
        int i; 
  
        pNode->endOfWord = false; 
  
        for (i = 0; i < NUM_LETTERS; i++) 
            pNode->next_child[i] = NULL; 
    } 
  
    return pNode; 
} 


void insert(node *root, const char *word) 
{ 
    int level; 
    int length = strlen(word); 
    int index; 
    
    node *pCrawl = root; 

    
    for (level = 0; level < length; level++) 
    { 
        index = CHAR_2_INDEX(word[level]); 
        if (!pCrawl->next_child[index]) 
            pCrawl->next_child[index] = getNode(); 
  
        pCrawl = pCrawl->next_child[index]; 
    } 
  
    // mark last node as leaf 
    pCrawl->endOfWord = true; 
    pCrawl->count++;
} 


bool search(struct TrieNode *root, const char *key) 
{ 
    int level; 
    int length = strlen(key); 
    int index; 
    struct TrieNode *pCrawl = root; 
  
    for (level = 0; level < length; level++) 
    { 
        index = CHAR_TO_INDEX(key[level]); 
  
        if (!pCrawl->children[index]) 
            return false; 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    return (pCrawl != NULL && pCrawl->isEndOfWord); 
} 