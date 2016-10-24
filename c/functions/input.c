 # include <stdio.h>

int get_input();

int main() {

  // creates variable lenght of 5 characters
  char string[5];
  // --- basic ---
  printf ("Please enter some input: ");
  // Waits for user input and saves it to var
  scanf("%s", string);
  // --- basic ---
  printf("The value you entered is: %s", string );

  // Successfully took input and saved to variable
  
  return 0;
}
    
