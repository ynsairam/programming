#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* link;
} Node;
Node *top = NULL;


void Push(int x) {
  Node *temp = (Node *)malloc(sizeof(Node *));
  temp->data=x;
  temp->link = top; 
  top = temp; 
}

void Pop() {
  Node *temp;
  if (top==NULL)
    return; 
  temp = top; 
  top = top->link; 
  free(temp);
}


void Print( ) {
  if (top==NULL)
    printf("List is empty\n"); 
  else {
    Node *temp=top;
    while(temp) {
      printf("%d ", temp->data);
      temp = temp->link; 
    }
    printf("\n");
  }
}
int main( ) {
  Print(); 
  Push(1); 
  Print(); 
  Push(2); 
  Print();
  Pop(); 
  Print(); 
  Push(3); 
  Print(); 
  Push(4);
  Print(); 
}
