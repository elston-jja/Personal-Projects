# include <stdio.h>

int main() {

  int var= 12;
  int* po;

  printf("The value for var currently is: %d\n", var);
  printf("The adress for var currenly is: %d\n", &var);

  po=&var;

  printf("When pointer po is set to the adress of var, it equals %d\n", *po);
  printf("The adress for pointer var is: %d\n", &po );

  var=19;

  printf("The new value of pointer var: %d\n", *po);
  printf("The new value of var: %d\n", var);
  return 0;
}
