#include <stdlib.h>
#include <stdio.h>

typedef long long ll;
typedef unsigned long long ull;
typedef struct Step{
	ll start;
	ull value;
	struct Step *next;
} Step;
typedef Step* pStep;

//----- global var -----//
pStep head = NULL, tail = NULL, curr = NULL;

//----- functions -----//
pStep
newStep(ll x, ull y)
{
	pStep newStep = (pStep)malloc(sizeof(Step));
	newStep->start = x;
	newStep->value = y;
	newStep->next = NULL;
	return newStep;
}


void
insertFront(pStep newStep)
{
	curr = head;
	while(curr != NULL && curr->value <= newStep->value){
		pStep temp = curr;
		curr = curr->next;
		free(temp);
	}
	newStep->next = curr;
	head = newStep;
	if(tail == NULL) tail = head;
	curr = head;
}

void
appendTail(pStep newStep)
{
	tail = tail->next = newStep;
}

void
insertMid(ll start, ull value)
{
	while(curr->next != NULL && curr->next->start < start)
		curr = curr->next;
	
	if(value > curr->value){
		pStep newstep = newStep(start, value);
		pStep temp = curr->next;
		curr->next = newstep;
		curr = temp;

		while(curr != NULL && curr->value <= value) {
			pStep temp = curr;
			curr = curr->next;
			free(temp);
		}
		newstep->next = curr;
	}
}

int
main()
{
	int f, g, a, b, p, q;
	ull ans = 0;

	scanf("%d", &f);
	scanf("%d %d", &a, &b);
	insertFront(newStep(a, b));
	for(int i = 1; i < f; i++){
		scanf("%d %d", &a, &b);
		appendTail(newStep(a, b));
	}

	curr = head;
	scanf("%d", &g);	
	scanf("%d %d", &a, &b);
	if(head->start >= a) insertFront(newStep(a, b));
	else insertMid(a, b);
	for(int i = 1; i < g; i++){
		scanf("%d %d", &a, &b);
		insertMid(a, b);
	}

	scanf("%d %d", &p, &q);

	pStep temp = head;
	while(temp != NULL){
		printf("%lld %lld \n", temp->start, temp->value);
		temp = temp->next;
	}

	curr = head;

	while(curr->next != NULL && curr->next->start < p) curr = curr->next;
	if(p > curr->start) curr->start = p;
	if(q < curr->start) curr = NULL;
	while(curr != NULL){
		if(curr->next == NULL || q < curr->next->start){
			ans += (q - curr->start + 1) * curr->value;
			break;
		}
		ans += ((curr->next->start - curr->start) * curr->value) % 10007;
		curr = curr->next;
	}
	printf("%lld\n", ans % 10007);
	//free();
}
