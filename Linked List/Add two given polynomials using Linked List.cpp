#include <iostream>

using namespace std;
class Node
{
    public:
    int coef;
    int deg;
    Node *next;
};

Node* push(Node* head_ref)
{
    int coef,deg;
    cout<<"Enter coefficient and degree: ";
    cin>>coef>>deg;
    Node* new_node = new Node();
    new_node->coef = coef;
    new_node->deg = deg;
    new_node->next= (head_ref);
    return new_node;
}

Node* polyadd(Node *poly1, Node *poly2)
{
    Node *nn,*poly3=NULL,*cur, *l1 = poly1, *l2=poly2;

    while(l1!=NULL && l2!=NULL)
    {
        nn = new Node();
        if (l1->deg==l2->deg)
        {
            nn->coef=l1->coef + l2->coef;
            nn->deg = l1->deg;
            nn->next = NULL;
            l1 = l1->next;
            l2 = l2->next;
        }
        else if (l1->deg < l2->deg)
        {
            nn->coef= l2->coef;
            nn->deg = l2->deg;
            nn->next = NULL;
            l2 = l2->next;
        }
        else
        {
            nn->coef= l1->coef;
            nn->deg = l1->deg;
            nn->next = NULL;
            l1 = l1->next;
        }
        if (poly3==NULL) {poly3 = nn; cur = nn;}
        else
        {
            cur->next = nn;
            cur=nn;
        }
    }

    while(l1)
    {
        nn = new Node();
        nn->coef=l1->coef;
        nn->deg = l1->deg;
        nn->next = NULL;
        l1= l1->next;
        if (poly3==NULL) {poly3 = nn; cur = nn;}
              else
              {
                  cur->next = nn;
                  cur=nn;
              }
    }

    while(l2)
    {
        nn = new Node();
        nn->coef=l2->coef;
        nn->deg = l2->deg;
        nn->next = NULL;
        l2= l2->next;
        if (poly3==NULL) {poly3 = nn; cur = nn;}
              else
              {
                  cur->next = nn;
                  cur=nn;
              }
    }
    return poly3;
}

Node* SortDesc(Node*head, int n)
 {
   int p,q;
   Node *temp=head;
   for(int i=0;i<n-1;i++)
   {
    for(int j=0;j<n-i-1;j++)
    {
      if(temp->deg<temp->next->deg)
      {
        p=temp->coef;
        q=temp->deg;
        temp->coef= temp->next->coef;
        temp->deg= temp->next->deg;
        temp->next->coef=p;
        temp->next->deg=q;
      }
      temp=temp->next;
    }
    temp=head;
  }
  return head;
 }

int main()
{
    Node *p1=NULL, *p2 = NULL;
    int n1,n2;
    cout<<"Enter the number of nodes in L1 and L2: ";
    cin>>n1>>n2;
    cout<<"\nFor List L1:\n";
    for(int i=0; i<n1; i++)
        p1 = push(p1);
    cout<<"\nFor List L2:\n";
    for(int i=0; i<n2; i++)
        p2 = push(p2);
    p1=SortDesc(p1,n1);
    p2=SortDesc(p2,n2);
    Node* p3=NULL,*t;
    p3 = polyadd(p1,p2);
    t=p3;
    cout<<"\nList L1:\n";
    while (p1!=NULL)
    {
     cout<<p1->coef<<"  x"<<p1->deg<<"\n";
     p1=p1->next;
    }
    cout<<"\nList L2:\n";
    while (p2!=NULL)
    {
     cout<<p2->coef<<"  x"<<p2->deg<<"\n";
     p2=p2->next;
    }
    cout<<"\nOutput:\n";
    while (t!=NULL)
    {
     cout<<t->coef<<"  x"<<t->deg<<"\n";
     t=t->next;
    }
    return 0;
}
