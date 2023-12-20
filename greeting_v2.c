#include <stdio.h>

/* Building upon the V1, this version allows the 
 * user to enter a name from terminal as a program 
 * argument */ 
int main(int argc, char *argv[]){
  if( argc < 2 ){ // First arg is the program name 
    puts("Please provide a name for the greeting!");
  }
  else{
    printf("Hello, %s!\n", argv[1]);
  }
  return(0);
}
