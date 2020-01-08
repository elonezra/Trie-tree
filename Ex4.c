#include <stdio.h>

#include <stdbool.h>

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


node *getNode() 
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




int main() 
{ 
   //char *str_local = { '\0' };

  char temp[WORD] = { '\0' };
  char position = 1;

  char line[LINE];
  char *ln = line;

  while (fgets (ln, LINE, stdin) != NULL)
    {
      //printf (" %s", line);

      while (*ln != '\0' && position > 0 && *ln != '\n')
	{
	  position = getword (ln);

	  strncpy (temp, ln, position);
	  


	  ln = (ln + position + 1);

	  for (int i = 0; *(temp+i) != '\0'; i++)
	    {

	      *(temp + i) = '\0';
	    }


	}
	ln = line;
    }
    node *root = getNode(); 
  
    // Construct trie 
    int i; 
    for (i = 0; i < ARRAY_SIZE(keys); i++) 
        insert(root, keys[i]); 
  

  int level = 0; 
    char str[20]; 
  
    // Displaying content of Trie 
    display(root, str, level); 
    printf("\n");
    displayR(root, str, level); 
    return 0; 
} 