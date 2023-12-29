#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE(array) sizeof(array) / sizeof(array[0])
#define BSIZE 64

/* Function prototypes (forward declaration)*/
char isterm(char* term);

int main(){
  char phrase[BSIZE];
  /* Get user input */ 
  printf("NATO word or phrase: ");
  fgets(phrase, BSIZE, stdin);

  char* match = strtok(phrase, " ");
  char ch;
  while(match){
    if((ch = isterm(match)) != '\0'){
      putchar(ch); 
    }
    match = strtok(NULL, " "); // Keep splitting the user string 
  }
  putchar('\n');
  return(0);
}

/* Convert NATO code to text */
char isterm(char* term){
  const char* nato[] = {"Alfa", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot",
                        "Golf", "Hotel", "India", "Juliett", "Kilo", "Lima",
                        "Mike", "November", "Oscar", "Papa", "Quebec", "Romeo",
                        "Sierra", "Tango", "Uniform", "Victor", "Whiskey",
                        "Xray", "Yankee", "Zulu"};

  const char* n;
  char* t;
  for(int i = 0; i < SIZE(nato); i++){
    n = nato[i];
    t = term;

    while( *n != '\0' ){
      if(toupper((int)*n) != toupper((int)*t)){ // Every character must match
        break;
      }
      // Increment character pointer 
      ++n;
      ++t; 
    }

    if(*n == '\0'){
      return(*nato[i]); // Return first character 
    }
  }
  return('\0'); // No matching NATO code 
}
