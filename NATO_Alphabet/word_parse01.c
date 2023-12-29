#include <stdio.h>
#include <string.h>

#define SIZE 64

int main(){
  char sometext[SIZE];
  
  printf("Type some text here: ");
  fgets(sometext, SIZE, stdin);

  char* match = strtok(sometext, " ");

  int i = 0;
  while(match){ // Loop when match != NULL
    printf("%d %s\n", ++i, match);
    /* NULL means keep 'dividing' the previous string */
    match = strtok(NULL, " ");
  }
  return(0);
}
