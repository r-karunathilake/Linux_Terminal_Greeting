#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE(array) sizeof(array) / sizeof(array[0])
#define BSIZE 64

/* Function prototypes (forward declaration)*/
char isterm(char* term);

int main(int argc, char* argv[]){
  if(argc < 2){
    fprintf(stderr, "Please supply a text file as argument\n");
    exit(1);
  }
  FILE* file = fopen(argv[1], "r");
  if(file == NULL){
    fprintf(stderr, "Unable to open '%s'\n", argv[1]);
    exit(1); 
  }

  int offset = 0;
  int ch; // Integer b/c reading from file
  char word[BSIZE];
  while((ch = fgetc(file)) != EOF){ // EOF is an integer 
    if(!isalpha(ch)){// End of a word detected by a nonalphabetic character 
      word[offset] = '\0';
      putchar(isterm(word)); // Check if the word is part of NATO code 
      memset(word, '\0', BSIZE); // Reset the buffer (optional)
      offset = 0; // Reset for next word in the text file 
      continue; // Find next word 
    }
    
    /* Found an alphabetic character */
    word[offset] = ch;
    ++offset;
    if(offset >= 64){
      fprintf(stderr, "Buffer overflow. Large word (> %d characters encountered!)\n", BSIZE);
    }
  }
  putchar('\n');

  fclose(file);
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

    /* Every character was a match? */ 
    if(*n == '\0'){
      return(*nato[i]); // Return first character 
    }
  }
  return('\0'); // No matching NATO code 
}
