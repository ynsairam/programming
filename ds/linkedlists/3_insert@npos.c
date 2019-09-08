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

void insert_npos(int d, int p) {
Node *temp = malloc(sizeof(Node));
temp->d = d;
temp->n = NULL;

if (p==1){
  temp->n = head; 
  head = temp;
  return;
}
Node *h = head; 
for(int i=0; i<p-2; i++)
    h = h->n;
temp->n = h->n;
h->n = temp;
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
int n, i, x, p;
printf("Num of elements: \n"); 
scanf("%d", &n);
for(i=0; i<n; i++) {
  printf("Enter the number \n");
  scanf("%d", &x); 
  printf("Enter the pos \n");
  scanf("%d", &p); 
  insert_npos(x, p); 
  print( );
}

return 0;
}
