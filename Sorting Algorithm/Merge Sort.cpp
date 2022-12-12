#include<iostream>
using namespace std;

template <typename T>
void print(T arr[],int n)
{
 for(int i=0; i<n; i++)
    cout<<arr[i]<<" ";
 cout<<endl;
}

template <typename T>
void Merge(T arr[], int start, int end)
{
 T temp[end];
 int x,y,z,mid;
 mid = (start + end)/2;
 z=0;
 x=start;
 y=mid+1;
 while(x<=mid && y<=end)
 {
  if(arr[x] < arr[y])
  {
    temp[z] = arr[x];
    ++x; ++z;
  }
  else
  {
    temp[z] = arr[y];
    ++y; ++z;
  }
 }
 while(x<=mid)
 {
    temp[z] = arr[x];
    ++x; ++z;
 }
 while(y<=end)
 {
    temp[z] = arr[y];
    ++y; ++z;
 }
 for(int i=start; i<=end; ++i)
    arr[i] = temp[i - start];
}

template <typename T>
void MergeSort(T arr[], int start, int end)
{
 if(start<end){
 int mid = (start + end)/2;
 MergeSort(arr,start,mid);
 MergeSort(arr,mid+1,end);
 Merge(arr,start,end);
 }
}

int main()
{
 int n,c;
 cout<<"Enter array size: ";
 cin>>n;
 cout<<"\n1.Integer\n2.Character\n";
 cout<<"\nEnter choice: ";
 cin>>c;
 if(c==1)
 {
  int a[n];
  cout<<"\nEnter "<< n <<" array elements:\n";
  for(int i=0; i<n; i++)
    cin>>a[i];
  cout<<"\nElements before Sorting:\n";
  print(a,n);
  MergeSort<int>(a,0,n-1);
  cout<<"\nElements after Sorting:\n";
  print(a,n);
 }
 if(c==2)
 {
  char a[n];
  cout<<"\nEnter "<< n <<" array elements:\n";
  for(int i=0; i<n; i++)
    cin>>a[i];
  cout<<"\nElements before Sorting:\n";
  print(a,n);
  MergeSort<char>(a,0,n-1);
  cout<<"\nElements after Sorting:\n";
  print(a,n);
 }
 return 0;
}
