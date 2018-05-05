#include <stdio.h>

int add(int n)
{
    n += 1;

    return n;
}

int main()
{
    int *ptr;
    int var;

    var = 2;

    ptr = &var;

    printf("The value of var is %d\n",*ptr);

    printf("The addresses of var and ptr are linked?\n");    


    var = add(*ptr);

    printf("Adding one to the pointer produces %d\n", var);

    printf("The address of var is %d\n", &var);
    printf("The address of ptr is %d", ptr);
    
    return 0;
}
