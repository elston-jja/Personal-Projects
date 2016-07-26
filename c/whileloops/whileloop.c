# include <stdio.h>

int main() {

	int i = 0;
	int checkvalue;
	int array[10] = {1,2,3,4,5,6,7,8,9,10};

	while (i < 10) {
		// get to print out a number only if greater than 5
		if (array[i] >= 5) {
			printf ("The current value is: %d \n",array[i]);
		}
		else if ( array[i] > 10 ) {
			break;
		}
		// Skip if less than 5
		i++;
		continue;
		}
	return 0;
	}