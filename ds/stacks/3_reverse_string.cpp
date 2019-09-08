#include <iostream>
#include <stack>
using namespace std; 

/*class Stack {
  private: 
    char A[101];
    int top; 
  public: 
    void Push(int x);
    void Pop(); 
    int Top(); 
    bool IsEmpty(); 
};*/

void Reverse(char c[], int n) {
  stack<char> S; 
  for(int i=0; i<n; i++) {
    S.push(c[i]); 
  }
  for(int i=0; i<n; i++) {
    c[i] = S.top(); 
    S.pop(); 
  }  
}
int main() {
  char c[51];
  printf("Enter a string\n"); 
  gets(c);
  Reverse(c, strlen(c));
  printf("output = %s\n", c);
}

