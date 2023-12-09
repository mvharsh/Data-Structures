#include<iostream>
using namespace std;
#define SIZE 3

class stack
{
  public:
    int s[SIZE];
    int top;
    void display();
    void push();
    void pop();
    bool isEmpty();
};

void stack::push()
{
  int elem;
  if(top < SIZE-1)
  {
    cout<<"Enter element: ";
    cin>>elem;
    top++;
    s[top] = elem;
  }
  else
    cout<<"\nSTACK OVERFLOW\n";
}

bool stack::isEmpty()
{
  if(top==-1)
    return true;
  else
    return false;
}

void stack::pop()
{
  if(!isEmpty())
  {
    top--;
  }
  else
    cout<<"\nSTACK UNDERFLOW\n";
}

void stack :: display()
{
  cout<<"STACK:\n";
  if(top==-1)
    cout<<"Empty"<<endl;
  for(int i=top; i>=0; i--)
    cout<<"["<<s[i]<<"]"<<endl;
}

int main()
{
  stack s1;
  int input=0,choice;
  s1.top = -1;
  while(input!=4)
  {
    cout<<"\n------ STACK OPERATIONS------\n";
    cout<<"\n1.Push\n2.Pop\n3.IsEmpty\n4.Exit\n";
    cout<<"\nEnter the operation: ";
    cin >> choice;
    switch(choice)
    {
      case 1:
          s1.push();
          s1.display();
          break;

      case 2:
          s1.pop();
          s1.display();
          break;

      case 3:
          if(s1.isEmpty())
               cout<<"STACK IS EMPTY\n";
  else
    cout<<"STACK IS NOT EMPTY\n";
          break;

      case 4:
          cout<<"\nProgram Ended\n";
          return 0;;
    }
  }
}

