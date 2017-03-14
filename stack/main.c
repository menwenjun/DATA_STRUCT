#include <stdio.h>
#include "stack.h"

int main(void)
{
	STACK *s;
	int i;

	s = createStack(100);
	
	disposeStack(s);
/*
	for(i = 0; i < 10; i++) {
		push(i, s);	
		printf("%d\t", top(s));
	}
	printf("\n");


	for(i = 0; i < 10; i++) {
		printf("%d\n", topAndTop(s));
	}

*/	
	return 0;
}
