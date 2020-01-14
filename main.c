#include"Ex4.h"
#include<stdio.h>
#include<stdlib.h>


int main() 
{ 


//   char line[LINE];
//   char *ln = line;

//   while (fgets (ln, LINE, stdin) != NULL)
//     {7

       

//     }
    char keys [][8]={"an", "ant", "all", "alloy", "aloe", "are", "ate", "be"};
   //char *str_local = { '\0' };


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
    //freeMemory(root);
    return 0; 
} 