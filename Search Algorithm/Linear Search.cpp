#include<iostream>
using namespace std;

void LinearSearch(int arr[], int n, int Key)
{
 int k =0;
 for(int i=0; i<n; i++)
 {
  if( Key == arr[i] )
  {
    k = 1;
    cout<<"\nElement found at index "<<i<<" and position "<<i+1;
  }
 }
 if( k == 0)
    cout<<"\nElement not found";
 cout<<endl;
}

int main()
{
 int n,key;
 cout<<"Enter array size: ";
 cin>>n;
 int arr[n];
 cout<<"\nEnter " << n << " array elements:\n";
 for(int i=0; i<n; i++)
    cin>>arr[i];
 cout<<"\nEnter key to search: ";
 cin>>key;
 LinearSearch(arr,n,key);
 return 0;
}
