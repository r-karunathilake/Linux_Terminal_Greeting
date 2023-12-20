#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h> // strcpy()

#define SIZE 64
#define BSIZE 256

/* Building upon V3, this version allows the 
 * user to enter a name from terminal as a program 
 * argument, customize greeting based on time of day, and
 * also displays the current time */ 
int main(int argc, char *argv[]){
  time_t now;
  struct tm *clock;
  
  // Hold the formatted time string
  char time_string[SIZE];

  // Get current time
  time(&now);
  clock = localtime(&now);
  
  /* %A: name for the current day of the week
   * %B: name for the current month
   * %Y: 4-digit year
   * %n: new line character
   * %r: time with AM or PM */
  strftime(time_string, SIZE, "Today is %A, %B, %d, %Y%nIt is %r%n", clock);

  printf("Greetings");
  // If user provided a name
  if( argc > 1 ){
    printf(", %s", argv[1]);
  }
  printf("!\n%s", time_string);

  const char filename[] = "quotes.txt";
  FILE *p_file;
  char buffer[BSIZE];
  char *p_return, *entry;
  int items = 0, saying; 

  // Start reading the text file with quotes 
  p_file = fopen(filename, "r");
  if(p_file == NULL){
    fprintf(stderr, "Unable to open file %s\n", filename);
    exit(1);
  }

  /* Allocate string storage memory, assume 100 entries 
   * for now and reallocate memory as needed later */ 
  char **list_quotes = (char **) malloc(sizeof(char *) * 100);

  while(!feof(p_file)){
    p_return = fgets(buffer, BSIZE, p_file);
    
    if(p_return == NULL){
      break;
    }
    entry = (char *) malloc(sizeof(char) * (strlen(buffer) + 1));
   
    if(entry == NULL){
      fprintf(stderr, "Unable to allocate memory!\n");
      exit(1);
    }

    strcpy(entry, buffer);
    *(list_quotes + items) = entry;
    items++;

    // Reallocate memory as necessary 
    if(items % 100 == 0){
      list_quotes = realloc(list_quotes, sizeof(char *) * (items + 100));

      if(list_quotes == NULL){
        fprintf(stderr, "Unable to reallocate memory\n");
        exit(1);
      }
    }
  }

  fclose(p_file);

  // Get random quote 
  srand((unsigned) time(NULL));
  saying = rand() % (items - 1);
  printf("%s", *(list_quotes + saying));

  return(0);
}
