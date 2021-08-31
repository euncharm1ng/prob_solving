#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
main()
{
	int input, output = 0, mult = 1, toAdd;
	scanf("%d", &input);

	time_t start = clock();
	while(input > 0){
		toAdd = input % 10;
		if(toAdd > 3) toAdd--;
		output += mult * toAdd;
		input /= 10;
		mult *= 9;
	}
	time_t end = clock();

	printf("%d\n", output);
	printf("%f\n", (end - start) / (double) CLOCKS_PER_SEC);
}
