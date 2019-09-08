#include <stdio.h>
#include <stdlib.h>
#define MAX_TOP 10
int A[MAX_TOP]; 
int top=-1; 

void push(int x) {
  if (top+1 == MAX_TOP) {
    printf("Stack overflow!!!\n");
    return;
  } 
  top = top+1; 
  A[top] = x; 
}

void pop() {
  top = top-1; 
}

int topElement() {
  return A[top]; 
}

int IsEmpty() {
  return (top==-1);
}

void Print() {
  int i; 
  printf("Stack: "); 
  for(i=0; i<= top; i++)
    printf("%d ", A[i]); 
  printf("\n"); 
}

int main() {
  top = -1; 
  push(2);  Print(); 
  push(10); Print(); 
  push(5); Print();
  pop(); Print(); 
  push(7); Print();  
}
