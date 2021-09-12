#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void
main()
{
        int num = 0;
        scanf("%d", &num);
        int* combination = (int*) malloc(sizeof(int) * num + 1);
		combination[0] = 1;
		combination[1] = 1; combination[2] = 1; combination[3] = 2; combination[4] = 4;
        for(int i = 5; i < num + 1; i++){
            combination[i] = combination[i - 1] + combination[i - 3] + combination[i-4];
        }
        printf("%d\n", combination[num]);
        
}