#include <stdio.h>
#include <stdlib.h>

typedef struct node_t{
int val;
int next;
int prev;
}node; 

int head;

#define MAX_NODES 10000
node np[MAX_NODES];
int npcount = 0;  
int sp[MAX_NODES];
int scount = -1; 

void init( ) {
   scount = -1; 
   npcount = 0;
   head = -1;
}

void printnp( ) {
	int i = head;
	printf("np[%d]: ", npcount);  
	while(i>=0) {
		printf("%d, ", np[i].val); 
		i = np[i].next;
	}
	printf("\n\n"); 
}

int get( ) {
	int i; 
	if (scount<0) {
		if (npcount == MAX_NODES-1)
			printf("Node pool overflow\n"); 
		i = npcount++;
		printf("get() is giving new node from node pool %d, Pools [%d, %d]\n", i, npcount, scount);
	}
	else {
		i = sp[scount--]; 
		printf("get() is giving reuse node from stackpool %d, Pools [%d, %d]\n", i, npcount, scount);
	}
	np[i].next = -1; 
	np[i].prev = -1; 
	return i;
}

void insert(int v) {
  printf("Inserting %d\n", v); 
  if (head<0) {
     head = get( );
     np[head].next = -1; 
     np[head].prev = -1;
     np[head].val = v; 
  } else {
     int i=head;
     int prev = -1;
     while(i>=0  && np[i].val < v) {
	prev = i; 
       	i = np[i].next;
     }
     int cur = get();
     np[cur].val = v; 
     np[cur].next = i;
     np[cur].prev = prev;
     if (i==head)
	head = cur;
     if (prev>=0)
     	np[prev].next = cur;
     if (i>=0)
	np[i].prev = cur; 
  }
}

void remov( int v) {
	printf("Removing %d\n", v); 
	int i = head; 
	int prev;
	while(i>=0 && np[i].val < v) {
		prev = i;
		i = np[i].next; 
	}
	if (np[i].val == v) {
		printf("%d found at %d\n", v, i); 
		np[prev].next = np[i].next; 
		if (np[i].next >=0)
			np[np[i].next].prev = prev; 
		if (scount == MAX_NODES-1)
			printf("Stack pool overflow\n"); 
		sp[++scount] = i; 
		printf("%d is added to stackpool at %d\n", i, scount);
	} else {
		printf("%d not found\n", v); 
	}
}

    

int main( ) {
  init();
  //Insert elements to a sorted linked list
  printnp(); 
  insert(12); 
  printnp(); 
  insert(8);
  printnp(); 
  insert(21); 
  printnp(); 
  remov(21); 
  printnp(); 
  insert(13); 
  printnp(); 
  remov(12); 
  printnp(); 
  insert(71); 
  printnp(); 
  remov(39); 
  printnp(); 
  insert(37); 
  printnp(); 
  return 0;
}

