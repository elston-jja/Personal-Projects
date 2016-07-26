#include <stdio.h>

int main(){
	int array[10] = {1,2,3,4,5,6,7,8,9,10};
	int factorial = 1;
	int i;

	for(i = 0; i < 10; i++) {
		factorial *= array[i] ;

	printf("The total number of the factorial is %d \n", factorial );
	}
return 0;
}