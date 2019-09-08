#include <stdio.h>
#include <stdlib.h>

typedef struct Node_t {
int d;
struct Node_t *n;
} Node;

Node *head;

void insertBeginning(int d) {
Node *temp = malloc(sizeof(Node));
temp->d = d;
temp->n = head;
head = temp;
}

void insertEnd(int d) {
Node *h = head; 
Node *temp = malloc(sizeof(Node));
temp->d = d;
temp->n = NULL;

if (head==NULL)
  head=temp;
else {
  Node *h = head; 
  while(h->n!=NULL)
    h = h->n;
  h->n = temp;
}
}

void print( ) {
Node *temp = head; 
printf("List is: ");
while(temp !=NULL) {
	printf("%d ", temp->d);
	temp = temp->n;
}
printf("\n");
}

int main( ) {
head = NULL;
int n, i, x;
printf("Num of elements: \n"); 
scanf("%d", &n);
for(i=0; i<n; i++) {
  printf("Enter the number \n");
  scanf("%d", &x); 
  insertBeginning(x); 
  //insertEnd(x);
  print( );
}

return 0;
}
