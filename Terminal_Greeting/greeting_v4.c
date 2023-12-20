#include <stdio.h>
#include <time.h>

#define SIZE 64
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

  return(0);
}

