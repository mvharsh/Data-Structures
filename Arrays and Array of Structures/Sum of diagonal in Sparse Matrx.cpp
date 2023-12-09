#include<iostream>
#define size 50
using namespace std;
class node
{
  public:
  int data;
  int col;
  node*next;
};
class sparse
{
  public:
  int nrow;
  node* row[size];
  sparse(int n)
  {
    for(int i=0;i<n;i++)
      row[i]=NULL;
    nrow=n;
  }
  void display();
  void sumofdiagonals();
  void createvaluenode(int,int,int);
};

void sparse::createvaluenode(int data,int i,int j)
{
  node*nn=new node();
  nn->data=data;
  nn->next=NULL;
  nn->col=j;
  if(row[i]==NULL)
  {
   row[i]=nn;
  }
  else
  {
    node*t=row[i];
    while(t->next!=NULL)
      t=t->next;
    t->next=nn;
  }
}

void sparse::display()
{
 for(int i=0;i<nrow;i++)
 {
  node*t=row[i];
  cout<<"\nThe non-zero elements of row "<<i<<" are :";
  while(t!=NULL)
  {
    cout<<t->data<<" ";t=t->next;
  }
 }
}

void sparse::sumofdiagonals()
{
 int sum=0;
 for(int i=0;i<nrow;i++)
 {
  node*t=row[i];
  while(t!=NULL)
  {
    if(i==t->col)
      sum+=t->data;
    t=t->next;
  }
 }
 cout<<"\n\nSum of the diagonal: "<<sum;
}

int main()
{
  int row,nrow,col,data,nz;
  cout<<"Enter no of rows : ";
  cin>>row;
  sparse s(row);
  int a[row][row];
  cout<<"Enter "<<row*row<<" sparse matrix elements:\n";
  for(int i=0;i<row;i++)
  {
    for(int j=0;j<row;j++)
    {
     cin>>a[i][j];
     if(a[i][j]!=0)
       s.createvaluenode(a[i][j],i,j);
    }
  }
  s.display();
  s.sumofdiagonals();
  return 0;
}
