#include<iostream>
#include<stdlib.h>
using namespace std;
class node
{
    public:
    int data;
    node*prev;
    node*next;
};
void search(node *head)
{
    int item,c=0,Z=0;
    node*temp=head;
    cout<<"ENTER AN ELEMENT TO SEARCH: ";
    cin>>item;
    while(temp->next!=head)
    {
        c++;
        if(temp->data==item)
        {
            cout<<"THE ELEMENT IS PRESENT IN POSITION "<<c;
            Z=1;
            break;
        }
          temp=temp->next;
    }
    if(Z==0)
        cout<<"ELEMENT NOT FOUND!!";

}
node* insert(node*head)
{
    int pos,count=0,i;
    node*temp=head;
    node*h=head;
    int item;
    while(h->next!=head)
    {
        count++;
        h=h->next;
    }
    count++;
    cout<<"ENTER POSITION TO INSERT: ";
    cin>>pos;
    if(pos>count+1)
    {
        cout<<"\nTHERE ARE ONLY "<<count<<"ELEMENTS PRESENT IN THE LIST";
        return temp;
    }
    cout<<"ENTER ELEMENT TO INSERT : ";
    cin>>item;
    if(pos==1)
    {
        node *newnode=new node();
        newnode->prev=temp->prev;
        newnode->data=item;
        newnode->next=temp;
        temp->prev->next=newnode;
        temp->prev=newnode;
        temp=newnode;
        return temp;
    }
    else if(pos<=count)
    {
        for(i=1;i<pos;i++)
        {
            if(i==(pos-1))
            {
                node*s=temp->next;
                node *newnode=new node();
                newnode->prev=temp;
                newnode->data=item;
                newnode->next=s;
                temp->next=newnode;
                s->prev=newnode;
                return head;
            }
            temp=temp->next;
        }
    }
     else if(pos==count+1)
        {
            node *newnode=new node();
            newnode->prev=temp->prev;
            newnode->data=item;
            newnode->next=temp;
            temp->prev->next=newnode;
            temp->prev=newnode;
            return head;
        }
}
node* delPos(node*head)
{
    int pos,count=0,i;
    node*temp=head;
    node*h=head;
    int item;
    while(h->next!=head)
    {
        count++;
        h=h->next;
    }
    count++;
    cout<<"ENTER POSITION TO DELETE: ";
    cin>>pos;
    if(pos>count+1)
    {
        cout<<"\nTHERE ARE ONLY "<<count<<" ELEMENTS PRESENT IN THE LIST\n";
        return temp;
    }
    else if(pos==1)
    {
      node*x=temp->next;
      node*y=temp->prev;
      x->prev=y;
      y->next=x;
      delete(temp);
      temp=x;
      return temp;
    }
    else if(pos<count)
    {
      for(i=1;i<pos;i++)
      {
          if(i==pos-1)
          {
             node*x=temp->next;
             node*y=temp->next->next;
             temp->next=y;
             y->prev=temp;
             delete(x);
             return head;
          }
          temp=temp->next;
      }
    }
     else if(pos==count)
        {
            node*x=temp->prev->prev;
            node*y=temp->prev;
            x->next=temp;
            temp->prev=x;
            delete(y);
            return head;
        }
    }
node*delkey(node*head)
{
    int data;
        cout<<"ENTER KEY : ";
        cin>>data;
        node*temp=head;
        if(temp->data==data)
        {
            node*y=temp->prev;
            node*x=temp->next;
            x->prev=y;
            y->next=x;
            delete(temp);
            head=x;
            return head;
        }
        while(temp->next!=head)
        {
           if(temp->next->data==data)
           {
               node*s=temp->next;
               node*x=s->next;
               delete(s);
               temp->next=x;
               x->prev=temp;
               return head;
           }
           temp=temp->next;
        }
        if(temp->next==head)
        {
            cout<<"\nKEY NOT FOUND";
            return head;
        }
}
void display(node*head)
{
    node*h=head;
    if(head==NULL)
    {
        cout<<"LIST EMPTY!!";
    }
    cout<<"\nELEMENTS IN THE LIST: ";
        while(h->next!=head)
        {
            cout<<h->data<<" ";
            h=h->next;
        }
        cout<<h->data;
}
int main()
{
    int choice,item;
    int n,c;
    node *head=NULL;
    cout<<"ENTER NO. OF ELEMENTS IN LIST : ";
    cin>>n;
    cout<<"ENTER "<<n<<" ELEMENTS : ";
    if(head==NULL)
    {
        node*n=new node();
        cin>>n->data;
        n->next=n;
        n->prev=n;
        head=n;
    }
    c=1;
    node*curr=head;
    while(c!=n)
    {
        node*nn=new node();
        cin>>nn->data;
        nn->next=head;
        nn->prev=curr;
        curr->next=nn;
        head->prev=nn;
        curr=nn;
        c++;

    }
    display(head);
    while(choice!=5)
    {
        cout<<"\n\n1.INSERTION\n2.DELETE BY POSITION\n3.DELETE BY KEY\n4.SEARCH ELEMENTS\n5.EXIT";
        cout<<"\nENTER YOUR CHOICE :";
        cin>>choice;
        switch(choice)
        {
        case 1:
            head=insert(head);
            display(head);
            break;
        case 2:
            head=delPos(head);
            display(head);
            break;
        case 3:
            head=delkey(head);
            display(head);
            break;
        case 4:
            search(head);
            break;
        case 5:
            exit(0);
        default:
            cout<<"Wrong input! Enter numbers from 1 to 5";
        }
    }
    return 0;
}
