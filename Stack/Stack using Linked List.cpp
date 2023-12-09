#include<iostream>
using namespace std;

class node
{
  public:
    int data;
    node* next;
};

node* push(node* h)
{
  int elem;
  if(h==NULL)
  {
    cout<<"Enter element: ";
    cin>>elem;
    node* nn = new node();
    nn->data = elem;
    return nn;
  }
  cout<<"Enter element: ";
  cin>>elem;
  node* nn = new node();
  nn->data = elem;
  nn->next = h;
  return nn;
}

bool isEmpty(node* h)
{
  if(h == NULL)
    return true;
  else
    return false;
}

node* pop(node* h)
{
  if(h==NULL)
  {
    cout<<"CANNOT DELETE\n";
    return h;
  }
  node* t = h->next;
  delete(h);
  return t;
}

void display(node* h)
{
    if(h==NULL)
     cout<<"NO ELEMENTS\n";
    else
    {
      while(h!=NULL)
      {
        cout<<"["<<h->data<<"]"<<endl;
        h=h->next;
      }
    }
}

int main()
{
  node* stack = NULL;
  int input=0,choice;
  while(input!=4)
  {
    cout<<"\n------ STACK OPERATIONS------\n";
    cout<<"\n1.Push\n2.Pop\n3.IsEmpty\n4.Exit\n";
    cout<<"\nEnter the operation: ";
    cin >> choice;
    switch(choice)
    {
      case 1:
          stack = push(stack);
          display(stack);
          break;

      case 2:
          stack = pop(stack);
          display(stack);
          break;

      case 3:
          if(isEmpty(stack))
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
