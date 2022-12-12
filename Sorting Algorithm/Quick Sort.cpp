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
int partition(T arr[], int low, int high, int pivot)
{
 int i = low;
 int j = low;
 while(i<=high)
 {
   if(arr[i] > pivot)
   {
    i++;
   }
   else
   {
    swap(arr[i], arr[j]);
    i++; j++;
   }
 }
 return j-1;
}

template <typename T>
void QuickSort(T arr[], int low, int high)
{
 if(low<high){
 int pivot = arr[high];
 int pos = partition(arr,low,high,pivot);
 QuickSort(arr,low,pos-1);
 QuickSort(arr,pos+1,high);
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
  QuickSort<int>(a,0,n-1);
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
  QuickSort<char>(a,0,n-1);
  cout<<"\nElements after Sorting:\n";
  print(a,n);
 }
 return 0;
}
