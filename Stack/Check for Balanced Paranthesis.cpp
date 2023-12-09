#include<iostream>
#include<stack>
using namespace std;
bool isBalanced(string expr)
{
   stack<char> s;
   char ch;
   for (int i=0; i<expr.length(); i++)
  {
      if (expr[i]=='('||expr[i]=='['||expr[i]=='{')
      {
         s.push(expr[i]);
         continue;
      }
      if (s.empty())
       return false;
      switch (expr[i])
      {
            case ')':
               ch = s.top();
               s.pop();
               if (ch=='{' || ch=='[')
                  return false;
                  break;
            case '}':
               ch = s.top();
               s.pop();
               if (ch=='(' || ch=='[')
                  return false;
                  break;
            case ']':
               ch = s.top();
               s.pop();
               if (ch =='(' || ch == '{')
                  return false;
                  break;
         }
      }
      return (s.empty());
}
int main()
{
   string expr;
   cout<<"Enter your expression:";
   cin>>expr;
   if (isBalanced(expr))
      cout << "The Parentheses are BALANCED in the given Expression"<<endl;
   else
      cout << "The Parentheses are NOT BALANCED in the given Expression"<<endl;
      return 0;
}
