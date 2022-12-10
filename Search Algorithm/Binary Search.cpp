#include<algorithm>
#include<iostream>
using namespace std;

int BinarySearch(int arr[], int left, int right, int Key)
{
 if(right>=left)
 {
   int mid = left + (right - left)/2;
   if(arr[mid] == Key)
        return mid + 1;
   if(arr[mid] > Key)
        return BinarySearch(arr,left,mid-1,Key);
   else
        return BinarySearch(arr,mid+1,right,Key);
 }
 else
    return -1;
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
 sort(arr,arr+n);
 cout<<"\nArray after Sorting:\n";
 for(int i=0; i<n; i++)
    cout<<arr[i]<<" ";
 cout<<"\n\nEnter key to search: ";
 cin>>key;
 int position = BinarySearch(arr,0,n,key);
 if(position == -1)
    cout<<"\nElement not found\n";
 else
    cout<<"\nElement found at position "<<position<<endl;
 return 0;
}
