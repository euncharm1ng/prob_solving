#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
	char from, to, *disks_loc;
	long step;
	struct Node* next;
} Node;
typedef Node* pNode;
typedef struct Queue{
	pNode head, tail;	
} Queue;
typedef Queue* pQueue;

/*----- global variable -----*/
char n, k;
pQueue q;

/*----- functions -----*/
void
free_node(pNode target)
{
	free(target->disks);
	free(target);
}

pNode
create_node(pNode parent, char disk_index, char to)
{
	pNode new_node = (pNode)malloc(sizeof(Node));
	new_node->disks_loc = (char*)malloc(sizeof(char) * (n + 1));
	strncpy(parent->disks, new_node->disks, (size_t)(n + 1));
	new_node->from = new_node->disks_loc[disk_index];
	new_node->disks_loc[disk_index] = to;
	new_node->step = parent->step + 1;
	new_node->next = NULL;
	return new_node;
}

pNode
create_first_node(char* disks, char disk_index, char to)
{
	pNode new_node = (pNode)malloc(sizeof(Node));
	new_node->disks_loc = (char*)malloc(sizeof(char) * (n + 1));
	strcpy(disks, new_node->disks);
	new_node->from = new_node->disks_loc[disk_index];
	new_node->disks_loc[disk_index] = to;
}

void
push(pNode new_node)
{
	if(q->head == NULL) 
		q->head = q->tail = new_node;
	else{
		q->tail->next = new_node;
		q->tail = new_node;
	}
}

pNode
pop()
{
	pNode ret = q->head;
	q->head = q->head->next;
	return ret;
}

void 
delete_q()
{
	pNode curr;
	while(q->head != q->tail){
		curr = q->head;
		q->head = q->head->next;
		free_node(curr);
	}
	free_node(q->head);
	q->head = q->tail = NULL;
}

long 
search()
{
	while(1){
		pNode curr = pop();
		bool match_base = false;
		while(n > 0 && curr->disks_loc[n] == k){
			n--;
			match_base = true;
		}
		if(match_base){
			if(n == 0) return curr->step;
			delete_q();
			curr->disks_loc = (pNode)realloc(curr->disks_loc, (size_t) (n+1));
		}
		char fir_rod = curr->disks_loc[1];
		char pos = 2;
		while(curr->disks_loc[pos] != fir_rod)
			pos++;
		char sec_rod = curr->disks_loc[pos];
		char thr_rod = (char)6 - fir_rod - sec_rod;
		if(curr->to != fir_rod){
			push(create_node(curr, 1, thr_rod));

			curr->disks_loc[1] = sec_rod;
			curr->step++;
			curr->from = fir_rod;
			curr->to = sec_rod;
			push(curr);
		}
		else{
			//curr->disks_loc[1] = (char)6 - fir_rod - curr->from;
			push(create_node(curr, 1, (char)6 - fir_rod - curr->from));
			curr->disks_loc[pos] = thr_rod;
			curr->step++;
			curr->from = sec_rod;
			curr->to = thr_rod;
			push(curr);
		}
	}
}

int
main()
{
	scanf("%hhd %hhd", &n, &k);
	char disk[n+1];
	for(char i = 1; i < 4; i++){
		char a, b;
		scanf("%hhd",&a);
		for(char j = 0; j < a; j++){
			scanf("%hhd", &b);
			disk[b] = i;
		}
	}
	q = (pQueue)malloc(sizeof(Queue));
	q->head = q->tail = NULL;

	for(int i = 1; i <= n; i++){
		printf("%d ", disk[i]);
	}
}

