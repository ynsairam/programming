#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
}Node;
struct Node* head;
void Insert(int data);
void Print();
void Delete(int n);

int main()
{
  head = NULL;
  Insert(2); 
  Insert(4); 
  Insert(6); 
  Insert(5); 
  Print(); 

  int n; 
  printf("Enter a position\n"); 
  scanf("%d", &n);
  Delete(n); 
  Print();
}

void Print( ) {
Node *temp = head;
printf("List is: ");
while(temp !=NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
}
printf("\n");
}


void Insert(int d) {
  Node *temp = malloc(sizeof(Node));
  temp->data = d;
  temp->next = head;
  head = temp;
}

void Delete(int n)
{
  struct Node* temp1=head; 
  if (n==1) {
    head = temp1->next; 
    free(temp1);
    return; 
  }
  int i; 
  for(i=0; i<n-2; i++)
    temp1 = temp1->next; 

  struct Node* temp2 = temp1->next; 
  temp1->next = temp2->next; 
  free(temp2);
}
