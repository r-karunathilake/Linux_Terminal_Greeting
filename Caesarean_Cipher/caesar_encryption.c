#include <stdio.h> 
#include <ctype.h>

int main(int argc, char* argv[]){
  // Default character shift 
  int shift = 'D' - 'A';
  
  // If the user provided a specific character shift 
  if(argc == 3){
    // Shift character range 
    char lower_ch = argv[1][0];
    char upper_ch = argv[2][0];

    // User characters validation
    if(isalpha(lower_ch) && isalpha(upper_ch)){
      int potentialShift = toupper(upper_ch) - toupper(lower_ch); 
      
      // Update the shift to match user requested character shift 
      if(shift >= -25 && shift <= 25){
        shift = potentialShift;
      }
      else{
        fprintf(stderr, "Warning: the user requested character shift %c to %c is NOT valid!\n", toupper(lower_ch), toupper(upper_ch));
      }
    }
  }

  int ch;
  while((ch = getchar()) != EOF){
    if(isupper(ch)){
      ch += shift; 
        if(ch > 'Z'){
          ch -= 26;
        }
        else if(ch < 'A'){
          ch += 26;
        }
    }
    else if(islower(ch)){
      ch += shift;
      if(ch > 'z'){
        ch -= 26;
      }
      else if (ch < 'a'){
        ch += 26;
      }
    }
    putchar(ch);
  }
  return 0;
}
