#include<iostream>
#define SIZE 10
using namespace std;
class linear
{
   public:
       int h;
       int a[SIZE];
       linear()
       {
        for(int i=0;i<SIZE;i++)
            a[i]=0;
       }

       void display()
        {
         cout<<"\n\nHASH TABLE:\n";
         for(int i=0;i<SIZE;i++)
            cout<<a[i]<<endl;
        }

       void insert()
       {
           int key;
           cout<<"\nEnter Element: ";
           cin>>key;
           for(int i=0;i<SIZE;i++)
           {
            int index=(key+i)%SIZE;
            if(a[index]==0)
            {
             a[index]=key;
             break;
            }
           }
           cout<<"Element entered";
            display();
        }

        void search()
        {
         int flag = 0;
         int data;
         cout<<"Enter the element you want to search: ";
         cin>>data;
         for(int i=0;i<SIZE;i++)
         {
           if(a[i]==data)
           {
             flag=1;
             cout<<"ELEMENT "<<data<<" FOUND AT INDEX "<<i;
           }
         }
         if(flag==0)
            cout<<"ELEMENT "<<data<<" NOT FOUND";
        }

};
int main()
{
  linear l;
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
         l.insert();
         break;

     case 2:
         l.search();
         break;

     case 3:
         return 0;
    }
  }
}
