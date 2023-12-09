#include<iostream>
using namespace std;
class set
{
public:
void union_set(int u1[],int u2[],int s1,int s2)
{
 cout<<"\nUnion: ";
 for(int i=0;i<s1;i++)
 {
 cout<<u1[i]<<" ";
 }
 for(int j=0;j<s2;j++)
 {
 int a;
 a=0;
 for(int i=0;i<s1;i++)
 {
 if(u1[i]==u2[j])
 {
 a=1;
 break;
 }
 }
 if(a!=1)
 {
 cout<<u2[j]<<" ";
 }
 }
}
void intersection(int u1[],int u2[],int s1,int s2)
{
 cout << "\nThe Intersection of the given 2 sets: \n";
 for(int j=0;j<s2;j++)
 {
 int a;
 a=0;
 for(int i=0;i<s1;i++)
 {
 if(u1[i]==u2[j])
 {
 a=1;
 break;
 }
 }
 if(a==1)
 {
 cout<<u2[j]<<" ";
 }
 
 }
 
}
void cardinality(int u1[],int u2[],int s1,int s2)
{
 int c1=0,c2=0;
 cout<<"Cardinality of set 1\n";
 for(int i=0;i<s1;i++)
 {
 c1+=1;
 }
 cout<<c1;
 cout<<"\nCardinality of set 2\n";
 for(int i=0;i<s2;i++)
 {
 c2+=1;
 }
 cout<<c2;
}
void membership(int u1[],int u2[],int s1,int s2)
{
 int temp,e;
 cout<<"enter element to search ";
 cin>>e;
 for(int i=0;i<s1;i++)
 {
 if(u1[i]==e)
 temp=1;
 }
 if(temp==1)
 cout<<"Element found in 1st array\n";
 for(int j=0;j<s2;j++)
 {
 if(u2[j]==e)
 temp=0;
 }
 if(temp==0)
 cout<<"Element found in 2nd array\n";
 }
void difference(int u1[],int u2[],int s1,int s2)
{
 cout<<"\nA-B: ";
 for(int i=0;i<s1;i++)
 { 
 int a;
 a=0;
 for(int j=0;j<s2;j++)
 {
 if(u2[j]==u1[i])
 {
 a=1;
 break;
 }
 }
 if(a!=1)
 {
 cout<<u1[i]<<" ";
 }
 }
cout<<"\nB-A: ";
for(int j=0;j<s2;j++)
 { int a;
 a=0;
 for(int i=0;i<s1;i++)
 {
 if(u1[i]==u2[j])
 {
 a=1;
 break;
 }
 }
 if(a!=1)
 {
 cout<<u2[j]<<" ";
 }
 }
 }
 
};
int main()
{
 set w;
 int s1,s2,i,j,a;
 cout<<"\nEnter the no. of elements of set 1 and set 2: ";
 cin>>s1>>s2;
 int u1[s1],u2[s2];
 cout<<"\nEnter elements of set 1: ";
 for(i=0;i<s1;i++)
 {
 cin>>u1[i];
 }
 cout<<"\nEnter elements of set 2: ";
 for(i=0;i<s2;i++)
 {
 cin>>u2[i];
 }
 cout<<"1. UNION\n2. INTERSECTION\n3. DIFFERENCE\n4. CARDINALITY\n5. MEMBERSHIP\n6. 
EXIT ";
 int choice;
 while(choice!=0)
 {
 cout<<"\n\nEnter your choice: ";
 cin>>choice;
 switch(choice)
 {
 case 1:
 w.union_set(u1,u2,s1,s2);
 break;
 case 2:
 w.intersection(u1,u2,s1,s2);
 break;
 case 3:
 w.difference(u1,u2,s1,s2);
 break;
 case 4:
 w.cardinality(u1,u2,s1,s2);
 break;
 case 5:
 w.membership(u1,u2,s1,s2);
 break;
 case 6:
 return 0;
 }
 }
 
}
