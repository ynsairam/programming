#include <iostream>
#include <stack>
#include <string>
using namespace std; 
bool IsPair(char opening, char closing) {
  if (opening == '(' && closing == ')') return true; 
  if (opening == '{' && closing == '}') return true; 
  if (opening == '[' && closing == ']') return true; 
  return false;
}
bool IsParanthesesBalanced(string exp) {
  stack<char> S; 
  for(int i=0; i<exp.length(); i++) {
    if (exp[i]=='(' || exp[i] == '{' || exp[i] == '[')
      S.push(exp[i]);
    else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
      if (S.empty() || !IsPair(S.top(), exp[i]))
        return false; 
      else
        S.pop(); 
    }
  }
  return S.empty() ? true:false; 
}
int main( ) {
  string expr; 
  cout<<"Enter an expression: ";
  cin >> expr;
  if (IsParanthesesBalanced(expr))
    cout << "Balanced\n";
  else
    cout << "Not Balanced\n";
}
