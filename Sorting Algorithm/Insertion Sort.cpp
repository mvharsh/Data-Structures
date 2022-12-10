#include<iostream>
using namespace std;

template <typename T>
void InsertionSort(int n)
{
 T a[n];
 int i, j;
 T temp;
 cout<<"\nEnter "<< n <<" array elements:\n";
 for(i=0; i<n; i++)
    cin>>a[i];
 for(i=1; i<n; i++)
 {
  temp = a[i];
  j = i-1;
  while( j>=0 && a[j]>temp )
  {
    a[j+1] = a[j];
    j--;
  }
  a[j+1] = temp;
 }
 cout<<"\nElements after Sorting:\n";
 for(i=0; i<n; i++)
    cout<<a[i]<<" ";
 cout<<endl;
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
    InsertionSort<int>(n);
 if(c==2)
    InsertionSort<char>(n);
}
