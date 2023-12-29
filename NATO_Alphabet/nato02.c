#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char* argv[]){
  const char* nato[] = {"Alfa", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot",
                        "Golf", "Hotel", "India", "Juliett", "Kilo", "Lima",
                        "Mike", "November", "Oscar", "Papa", "Quebec", "Romeo",
                        "Sierra", "Tango", "Uniform", "Victor", "Whiskey",
                        "Xray", "Yankee", "Zulu"};

  if(argc < 2){
    fprintf(stderr, "Please supply a text file as argument\n");
    exit(1);
  }

  FILE* n = fopen(argv[1], "r");
  if(n == NULL){
    fprintf(stderr, "Unable to open '%s'\n", argv[1]);
    exit(1);
  }
 
  /* Use an integer variable for reading characters 
   * from a file because EOF flag at the end of a \
   * file is an int value. */
  int ch;
  while((ch=fgetc(n)) != EOF){
    if(!isalpha(ch)){
      continue;
    }
    printf("%s ", nato[toupper(ch) - 'A']);
  }
  putchar('\n');

  fclose(n);
  return(0);
}
