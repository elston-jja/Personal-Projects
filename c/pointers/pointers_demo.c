 # include <stdio.h>

int get_input();

int main() {

  int* p1;
  int var2=10;

  printf("The address of var2 : %d\n",&var2);
  printf("The value of var2 : %d\n",var2);

  p1=&var2;

  printf("The address of p1 is: %d\n", p1);
  printf("The value of p1 is: %d\n", *p1);

  var2=11;

  printf("The Address of p1 is: %d\n", p1);
  printf("The value of p1 is: %d\n", *p1);

  *p1=2;

  printf("The Address of var2 : %d\n ", &var2);
  printf("The value of var2 is: %d\n ", var2);

  return 0;
}    
