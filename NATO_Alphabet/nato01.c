#include <stdio.h>
#include <ctype.h>

#define SIZE 64

int main(){
  const char* nato[] = {"Alfa", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot",
                        "Golf", "Hotel", "India", "Juliett", "Kilo", "Lima",
                        "Mike", "November", "Oscar", "Papa", "Quebec", "Romeo",
                        "Sierra", "Tango", "Uniform", "Victor", "Whiskey",
                        "Xray", "Yankee", "Zulu"};

  char phrase[SIZE];
  
  /* Get user input */ 
  printf("Enter a word or phrase for NATO translation: ");
  fgets(phrase, SIZE, stdin);

  char ch;
  for(int i = 0; i < SIZE; i++){
    ch = toupper(phrase[i]);
    if(!isalpha(ch)){
      continue;
    }
    printf("%s ", nato[ch - 'A']);
  }
  putchar('\n');

  return 0;
}
