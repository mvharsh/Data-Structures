#include<iostream>
using namespace std;

#define MAX 100

void insert_heapify(int arr[], int n, int i)
{
 if(i!=0)
 {
   int parent = (i-1)/2;
   if( arr[i] > arr[parent] )
     swap( arr[i], arr[parent] );
   insert_heapify(arr, n, parent);
 }
}

void insertNode(int arr[], int& n, int Key)
{
 arr[n] = Key;
 n = n + 1;
 insert_heapify(arr, n, n-1);
}

void delete_heapify(int arr[], int n, int i)
{
 int largest = i;
 int l = 2*i + 1;
 int r = 2*i + 2;

 if( l < n && arr[l] > arr[largest])
    largest = l;

 if( r < n && arr[r] > arr[largest])
    largest = r;

 if(largest != i)
 {
    swap( arr[i], arr[largest]);
    delete_heapify(arr, n, largest);
 }
}

void deleteNode(int arr[], int& n)
{
 int lastElem = arr[n-1];
 arr[0] = lastElem;
 n = n - 1;
 delete_heapify(arr, n, 0);
}

void display(int arr[],int n)
{
 for(int i=0; i<n; i++)
    cout<<arr[i]<<" ";
 cout<<endl;
}

bool searchNode(int arr[], int n, int key)
{

 for(int i=0; i<n; i++)
 {
  if( key == arr[i] )
  {
    return true;
  }
 }
 return false;
}

int main()
{
 int arr[MAX];
 int ch, key;
 int n=0;
 while(1)
 {
  cout<<"\n== MAX HEAP ==\n";
  cout<<"1.Insert Node\n";
  cout<<"2.Delete Node\n";
  cout<<"3.Search Node\n";
  cout<<"4.Display Node\n";
  cout<<"5.Exit\n";
  cout<<"Enter choice: ";
  cin>>ch;
  switch(ch)
  {
    case 1:
        cout<<"\nEnter element to insert: ";
        cin>>key;
        insertNode(arr,n,key);
        cout<<"Element inserted";
        cout<<"\nMax Heap: ";
        display(arr,n);
        break;

    case 2:
        deleteNode(arr,n);
        cout<<"Element deleted";
        cout<<"\nMax Heap: ";
        display(arr,n);
        break;

    case 3:
        cout<<"\nEnter element to search: ";
        cin>>key;
        if(searchNode(arr,n,key))
            cout<<"Element found\n";
        else
            cout<<"Element not found\n";
        break;

    case 4:
        cout<<"\nMax Heap: ";
        display(arr,n);
        break;

    case 5:
        return 0;
  }
 }
}
