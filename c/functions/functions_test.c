# include <stdio.h>

int print_big(int big);

int main() {

	int i;
	int array[] = {5,11,15,9,10};

	for(i = 0; i < 5; i++) {
		print_big(array[i]);
	}	
	return 0;
}

int print_big(int big) {
	if (big > 10) {
		printf("%d is big\n",big);
	}
}