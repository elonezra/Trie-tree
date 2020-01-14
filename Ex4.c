#include <stdio.h>
#include<string.h>
#include<stdlib.h>



#define WORD (int)30
#define LINE (int)255
#define CHAR_2_INDEX(letter) ((int)letter-(int)'a'); //return asci's value of letter
#define NUM_LETTERS (int)26
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0])) 


typedef enum {fls=0, tru=1} boolean;

typedef struct Node { 
int count;
char letter;
struct node * next_child[NUM_LETTERS];
boolean endOfWord ;
} node;


node *getNode(void) 
{ 
    node *pNode = NULL; 
    
    pNode = ( node *)malloc(sizeof(node)); 
  
    if (pNode) 
    { 
        int i; 
  
        pNode->endOfWord = fls; 
  
        for (i = 0; i < NUM_LETTERS; i++) 
            pNode->next_child[i] = NULL; 
    } 
     pNode->count = 0;
    return pNode; 
} 


void insert(node *root, const char *word) 
{ 
    int level; 
    int length = strlen(word); 
    int index; 
    char c;
    
    node *pCrawl = root; 

    
    for (level = 0; level < length; level++) 
    { 
        c = tolower(word[level]);
        index = CHAR_2_INDEX(c); 
        if (!pCrawl->next_child[index]) 
            pCrawl->next_child[index] = getNode(); 
  
        pCrawl = pCrawl->next_child[index]; 
    } 
  
    // mark last node as leaf 
    pCrawl->endOfWord = tru; 
    pCrawl->count++;
  
} 


boolean search(node *root, const char *word) 
{ 
    int level; 
    int length = strlen(word); 
    int index; 
    node *pCrawl = root; 
  
    for (level = 0; level < length; level++) 
    { 
        index = CHAR_2_INDEX(word[level]); 
  
        if (!pCrawl->next_child[index]) 
            return fls; 
  
        pCrawl = pCrawl->next_child[index]; 
    } 
  

    return (pCrawl != NULL && pCrawl->endOfWord); 
} 

int wordAmount(node *root, const char *word) 
{

    int level; 
    int length = strlen(word); 
    int index; 
    node *pCrawl = root; 
  
    for (level = 0; level < length; level++) 
    { 
        index = CHAR_2_INDEX(word[level]); 
  
        if (!pCrawl->next_child[index]) 
            return fls; 
  
        pCrawl = pCrawl->next_child[index]; 
    } 
  

    return pCrawl->count; 
}



   void display( node* root, char str[], int level) 
{ 
    // If node is leaf node, it indicates end 
    // of string, so a null character is added 
    // and string is displayed 

      if ((root)->endOfWord  )  
    { 
        str[level] = '\0'; 

        printf("%s ",str); 
        printf("%d \n",root->count);
    } 
    int i; 
    for (i = 0; i < NUM_LETTERS; i++)  
    { 
        // if NON NULL child is found 
        // add parent key to str and 
        // call the display function recursively 
        // for child node 
        if (root->next_child[i] != NULL)  
        { 
            str[level] = i + 'a'; 
            display(root->next_child[i], str, level + 1); 
        } 
    } 
 
} 

   void displayR( node* root, char str[], int level) 
{ 
    // If node is leaf node, it indicates end 
    // of string, so a null character is added 
    // and string is displayed 

  
    int i; 
    for (i = NUM_LETTERS -1; i>= 0; i--)  
    { 
        // if NON NULL child is found 
        // add parent key to str and 
        // call the display function recursively 
        // for child node 
        if (root->next_child[i] != NULL)  
        { 
            str[level] = i + 'a'; 
            displayR(root->next_child[i], str, level + 1); 
        } 
    } 
     if ((root)->endOfWord  )  
    { 
        str[level] = '\0'; 

        printf("%s ",str); 
        printf("%d \n",root->count);
    } 
} 

void freeMemory(node* curs)
{
    free_all(curs);
}

void free_all(node* curs)
{
    int i;
    if(!curs) return;   // safe guard including root node. 

    // recursive case (go to end of trie)
    for (i = 0; i < 27; i++)
       free_all(curs->next_child[i]);


    // base case
    free(curs);
}