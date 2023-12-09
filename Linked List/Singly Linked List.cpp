#include<iostream>
#include<cstdlib>
using namespace std;

class node
{
  public:
  int data;
  node* next;
};

void display(node* n)
{
  while(n!=NULL)
  {
    cout<<n->data<<"->";
    n=n->next;
  }
  cout<<"NULL"<<endl;
}

void search(node *h)
{
    int count=0,k=0,key;
    cout<<"\nEnter the data you want to search: ";
    cin>>key;
    while(h!=NULL)
    {
       count++;
       if(h->data==key)
       {
        k=1;
        cout<<"\nData found at position "<<count<<"\n\n";
        break;
       }
       h=h->next;
    }
   if(k==0)
   cout<<"\nData not found\n\n";
}

node* insPos(node* h)
{
  node* n=h;
  int count=0,pos,new_data;
  cout<<"\nEnter the position you want to insert: ";
  cin>>pos;
  if(pos==1)
  {
    cout<<"\nEnter the data you want to insert: ";
    cin>>new_data;
    node* newn=new node();
    newn->data=new_data;
    newn->next=n;
    n=newn;
    cout<<"\nNode inserted\n\n";
    cout<<"\nList after inserting:\n";
    display(n);
    return n;
  }
  while(n!=NULL)
  {
    count++;
    if(count==pos-1)
        break;
    n=n->next;
  }
  if(n==NULL)
  {
    cout<<"\nPosition not found\n\n";
    return h;
  }
  cout<<"\nEnter the data you want to insert: ";
  cin>>new_data;
  node* newn=new node();
  newn->data=new_data;
  newn->next=n->next;
  n->next=newn;
  cout<<"\nNode inserted\n\n";
  cout<<"\nList after inserting:\n";
  display(h);
  return h;
}

node* delPos(node* h)
{
  int count=0,pos;
  node* cur=h;
  if(cur==NULL)
  {
    cout<<"\nNo element in list\n\n";
    return h;
  }
  cout<<"\nEnter the position which you want to delete: ";
  cin>>pos;
  if(pos==1)
  {
   node* del=cur;
   cur = del->next;
   delete(del);
   cout<<"\nList after deleting:\n";
   display(cur);
   return cur;
  }
  else
  {
   while(cur!=NULL)
   {
    count++;
    if(count==(pos-1))
      break;
    cur=cur->next;
   }
   if(cur==NULL || cur->next==NULL)
   {
    cout<<"\nPosition not found\n\n";
    return h;
   }
   node* del=cur->next;
   cur->next=cur->next->next;
   delete(del);
   cout<<"\nNode deleted\n\n";
   cout<<"\nList after deleting:\n";
   display(h);
   return h;
  }
}

node* delKey(node* h)
{
  node* n=h;
  int key;
  if(n==NULL)
  {
    cout<<"\nNo element to delete\n";
    return h;
  }
  cout<<"\nEnter the key to delete: ";
  cin>>key;
  if(n->data==key)
  {
    h=n->next;
    delete(n);
    cout<<"\nNode deleted\n\n";
    cout<<"\nList after deleting:\n";
    display(h);
    return h;
  }
  while(n!=NULL)
  {
    if(n->next!=NULL && n->next->data==key)
    {
      node* t=n->next;
      n->next=t->next;
      delete(t);
      cout<<"\nNode deleted\n\n";
      cout<<"\nList after deleting:\n";
      display(h);
      return h;
    }
    n=n->next;
  }
  if(n==NULL)
  {
    cout<<"Key not found"<<endl;
    return h;
  }
}

int main()
{
  node* head = NULL;
  int choice=0;
  while(choice!=5)
  {
  cout<<"\n\n"<< " LINKED LIST "<<"\n\n";
  cout<<"1.Insert at given position\n2.Delete at given position\n3.Delete by key\n4.Search data\n5.Exit\n\n";
  cout<<"Enter the operation: ";
  cin>>choice;
  switch(choice)
  {
   case 1:
       cout<<"\nOriginal List:\n";
       display(head);
       head = insPos(head);
       break;

   case 2:
       cout<<"\nOriginal List:\n";
       display(head);
       head = delPos(head);
       break;

   case 3:
       cout<<"\nOriginal List:\n";
       display(head);
       head = delKey(head);
       break;

   case 4:
       cout<<"\nThe List:\n";
       display(head);
       search(head);
       break;

   case 5:
       cout<<"\nProgram ended";
       exit(0);

   default:
      cout<<"Wrong input! Enter numbers from 1 to 4";
   }
  }
  return 0;
}
