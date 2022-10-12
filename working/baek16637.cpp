#include <iostream>

using namespace std;

int operand[10];
int n;
char operation[10];

long
calc(int sign_pos, long lhs, long rhs){
{
	if(operation[sign_pos] == '+') return lhs + rhs;
	else if(operation[sign_pos] == '-') return lhs - rhs;
	else if(operation[sign_pos] == '*') return lhs * rhs;
}

long 
back_track()
{
}

int
main()
{
	scanf("%d ", &n);
	scanf("%d", &operand[0]);
	for(int i = 0; i < n/2; i++)
		scanf("%c%d", &operation[i], &operand[i+1]);

	printf("%ld\n", max(back_track(0), calc(0, back_track(1))));
}
