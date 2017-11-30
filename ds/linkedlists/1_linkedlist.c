#include <stdio.h>
#include <stdlib.h>

typedef struct Node_t {
int d;
struct Node_t *n;
} Node;

Node *head;

void insert(int d, int n) {
Node *temp = malloc(sizeof(Node));
temp->d = d;
temp->n = head;
head = temp;
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
int n;
printf("Num of elements: \n"); 
scanf("%d", &n);

    insert(2, 1); //2
    insert(3, 2); //2, 3
    insert(4, 1); //4, 2, 3
    insert(5, 2); //4, 5, 2, 3
    print( );
return 0;
}
