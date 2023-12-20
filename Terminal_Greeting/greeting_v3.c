#include <stdio.h>
#include <time.h>

/* Building upon V2, this version allows the 
 * user to enter a name from terminal as a program 
 * argument and customize the greeting based on 
 * time of day */ 
int main(int argc, char *argv[]){
  time_t now;
  struct tm *clock;
  int hour;

  // Get current time
  time(&now);
  clock = localtime(&now);
  hour = clock->tm_hour;

  printf("Good ");
  if( hour < 12 ){
    printf("morning");
  }
  else if( hour < 17 ){
    printf("afternoon");
  }
  else{
    printf("evening");
  }
  
  // If user provided a name 
  if( argc > 1 ){
    printf(", %s", argv[1]);
  }

  /* Ensure the output end in a new line 
   * in all code flows */ 
  putchar('\n');

  return(0);
}

