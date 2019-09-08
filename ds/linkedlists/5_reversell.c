#include <stdio.h>
#include <stdlib.h>

typedef struct Node_t {
  int data; 
  struct Node_t *next; 
} Node;

Node* head; 

Node* Reverse() {
  Node *curr = head, *prev = NULL, *next = NULL; 
  while(curr != NULL) {
    next = curr->next;
    curr->next = prev; 
    prev = curr;
    curr = next;
  }
  head = prev;
  return head;
}


void insertEnd(int d) {
  Node *h = head;
  Node *temp = malloc(sizeof(Node));
  temp->data = d;
  temp->next = NULL;

  if (head==NULL)
    head=temp;
  else {
    Node *h = head;
    while(h->next!=NULL)
      h = h->next;
    h->next = temp;
  }
}

void print( ) {
  Node *temp = head;
  printf("List is: ");
  while(temp !=NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
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
    //insertBeginning(x);
    insertEnd(x);
    print( );
  }
  head = Reverse();
  print( );
  return 0;
}
