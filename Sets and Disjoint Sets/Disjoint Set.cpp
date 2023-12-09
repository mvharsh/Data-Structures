#include<iostream>
using namespace std;

class Set
{
 public:
 int data;
 int rank;
 Set* parent;

 Set(int d)
 {
   data = d; rank = 0; parent = this;
   cout<<"Created Set:"<<data<<" Rank:"<<rank<<" Parent:"<<parent->data<<endl;
 }
 Set* FindParent(Set&);
 void Union(Set&, Set&);
};

Set* FindParent(Set& s)
{
 if( s.data == s.parent->data )
    return s.parent;
 else
    return FindParent(*(s.parent));
}

void Union(Set& a, Set& b)
{
 Set* pa = FindParent(a);
 Set* pb = FindParent(b);
 if(pa->data == pb->data)
    return;
 if(pa->rank < pb->rank)
    a.parent = pb;
 else if(pa->rank > pb->rank)
    b.parent = pa;
 else
 {
    b.parent = pa;
    a.rank +=1;
 }

 cout<<"\nUNION of "<<a.data<<" & "<<b.data<<endl;
 cout<<"\tRank of "<<a.data<<" = "<<a.rank<<endl;
 cout<<"\tParent of "<<a.data<<" = "<<a.parent->data<<endl;
 cout<<"\tRank of "<<b.data<<" = "<<b.rank<<endl;
 cout<<"\tParent of "<<b.data<<" = "<<b.parent->data<<endl;
}

int main()
{
 Set s1(1);
 Set s2(2);
 Set s3(3);
 Set s4(4);
 Set s5(5);
 Set s6(6);

 Union(s1,s3);
 Union(s2,s4);
 Union(s3,s5);
 Union(s4,s6);

 return 0;
}
