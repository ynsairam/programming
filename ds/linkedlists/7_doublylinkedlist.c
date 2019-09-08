#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
   int data; 
   struct Node *next;
   struct Node *prev;
}Node;
struct Node* head;

Node * GetNewNode(int x) {
   Node *temp = (Node *)malloc(sizeof(Node)); 
   temp->data = x; 
   temp->next = NULL; 
   temp->prev = NULL;
   return temp;
}

void InsertAtHead(int x) {
   Node *temp = GetNewNode(x);
   if (head == NULL) {
   head = temp;
   return;
   }
   head->prev = temp;
   temp->next = head;
   head = temp;
}
void Print() {
   Node * temp = head; 
   printf("Forward: "); 
   while(temp != NULL) {
      printf("%d ", temp->data); 
      temp = temp->next;
   }
   printf("\n"); 
}

void ReversePrint() {
   Node * temp = head;
   if (temp==NULL) return;
   while(temp->next != NULL)
	temp = temp->next; 
 
   printf("Reverse: "); 
   while(temp != NULL) {
      printf("%d ", temp->data); 
      temp = temp->prev;
   }
   printf("\n"); 
}

int main( ){
   head = NULL;
   InsertAtHead(2); Print(); ReversePrint();  
   InsertAtHead(4); Print(); ReversePrint();  
   InsertAtHead(6); Print(); ReversePrint();  
   InsertAtHead(8); Print(); ReversePrint();  
   
   return 0;
} 
