#include<iostream>
#define size 10
using namespace std;

class node
{
  public:
  int data;
  int col;
  node*next;
};

class hash
{
  public:
  int nrow;
  node* row[size];
  hash(int n)
  {
    for(int i=0;i<n;i++)
      row[i]=NULL;
    nrow=n;
  }
  void display();
  void search();
  void insert();
};

void hash::insert()
{
  int data;
  cout<<"\nEnter element to insert: ";
  cin>>data;
  node*nn=new node();
  nn->data=data;
  nn->next=NULL;
  int h=data%size;
  if(row[h]==NULL)
  {
   row[h]=nn;
  }
  else
  {
    node*t=row[h];
    while(t->next!=NULL)
      t=t->next;
    t->next=nn;
  }
  display();
}

void hash::display()
{
 for(int i=0;i<nrow;i++)
 {
  node*t=row[i];
  cout<<"\nThe elements of row "<<i<<" are :";
  while(t!=NULL)
  {
    cout<<t->data<<" ";
    t=t->next;
  }
 }
}

void hash::search()
{
 int data,flag=0;
 cout<<"\nEnter element to search: ";
 cin>>data;
 for(int i=0;i<nrow;i++)
 {
  node*t=row[i];
  while(t!=NULL)
  {
    if(t->data == data)
    {
     flag=1;
     cout<<"\nELEMENT "<<data<<" FOUND AT INDEX "<<i;
    }
    t=t->next;
  }
 }
 if(flag==0)
    cout<<"\nELEMENT NOT FOUND";
}


int main()
{
  hash h(size);
  int choice;
  while(1)
  {
    cout<<"\n\n---------HASH-----------";
    cout<<"\n1.INSERT\n2.SEARCH\n3.EXIT\n\n";
    cout<<"Enter choice: ";
    cin>>choice;
    switch(choice)
    {
     case 1:
         h.insert();
         break;

     case 2:
         h.search();
         break;

     case 3:
         return 0;
    }
  }
}
