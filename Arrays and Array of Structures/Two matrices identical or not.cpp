#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
 int r1,c1,r2,c2,i,j,isEqual;
 cout<<"Enter row and column of Matrix A:\n";
 cin >> r1 >> c1;
 cout<<"Enter row and column of Matrix B:\n";
 cin >> r2 >> c2;
 if(r1!=r2 || c1!=c2)
 {
   cout << "\nMatrix A is NOT EQUAL to Matrix B\n";
   exit(0);
 }
 int a[r1][c1],b[r2][c2];
 cout<<"\nEnter Matrix A elements:\n";
 for(i=0;i<r1;i++)
    for(j=0;j<c1;j++)
      cin >> a[i][j];
 cout<<"\nEnter Matrix B elements:\n";
 for(i=0;i<r2;i++)
    for(j=0;j<c2;j++)
      cin >> b[i][j];
 cout<<"\nMatrix A:\n";
 for(i=0;i<r1;i++)
   {
    for(j=0;j<c1;j++)
     cout << a[i][j] << "\t";
    cout<< "\n";
   }
 cout<<"\nMatrix B:\n";
 for(i=0;i<r2;i++)
   {
    for(j=0;j<c2;j++)
     cout << b[i][j] << "\t";
    cout<< "\n";
   }

 if(r1==r2 && c1==c2)
 {
    isEqual = 0;
     for(i=0;i<r1;i++)
     {
       for(j=0;j<c1;j++)
       {
        if(a[i][j] != b[i][j])
        {
          isEqual = 1;
          break;
        }
       }
     }
     if(isEqual == 0)
        cout << "\nMatrix A is EQUAL to Matrix B\n";
     else
        cout << "\nMatrix A is NOT EQUAL to Matrix B\n";
 }
 return 0;
}
