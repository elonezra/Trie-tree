#include"Ex4.h"
#include<stdio.h>
#include<stdlib.h>


int split(char *str, char *arr[10]){
    int beginIndex = 0;
    int endIndex;
    int maxWords = 10;
    int wordCnt = 0;

    while(1){
        while(isspace(str[beginIndex])){
            ++beginIndex;
        }
        if(str[beginIndex] == '\0')
            break;
        endIndex = beginIndex;
        while (str[endIndex] && !isspace(str[endIndex])){
            ++endIndex;
        }
        int len = endIndex - beginIndex;
        char *tmp = calloc(len + 1, sizeof(char));
        memcpy(tmp, &str[beginIndex], len);
        arr[wordCnt++] = tmp;
        beginIndex = endIndex;
        if (wordCnt == maxWords)
            break;
    
        free(tmp);
    }
    return wordCnt;
}

int main() 
{ 

  char** keys = malloc(2 * sizeof(*keys));
  char line[LINE];
  char *ln = line;
  char *token;
  int counter = 0;
  int p= 0;
    //////// File Read //////////////

  while (fgets (ln, LINE, stdin) != NULL)
    {
       p = split(ln,keys+counter);
       counter +=p;
    }


    node *root = getNode(); 
  
    // Construct trie 
    int i; 
    for (i = 0; i < counter; i++) 
        insert(root, keys[i]); 
  

    int level = 0; 
    char str[20]; 
  
    // Displaying content of Trie 
    display(root, str, level); 
    printf("\n");
    displayR(root, str, level); 
    size_t n = sizeof(keys)/sizeof(keys[0]);
    for (size_t j = 0; j < n; j++)
    {
        /* code */
         free(keys[j]);
    }
    
    free(keys);
    freeMemory(root);

    return 0; 
} 