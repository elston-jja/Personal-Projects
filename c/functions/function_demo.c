# include <stdio.h>

int foo(int bar);

int main() { 
	printf("The function outputs : %d ",foo(90));
}

int foo(int bar) {
	return bar *2;
}
