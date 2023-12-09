#include <stdio.h>
int main()
{
  int a[10][10],trans[10][10],i,j,r,c,sum=0;
  printf("Enter rows and column:\n");
  scanf("%d%d",&r,&c);
  printf("Enter matrix elements:\n");
  for(i=0;i<r;i++)
    for(j=0;j<c;j++)
     {
       scanf("%d",&a[i][j]);
       trans[j][i] = a[i][j];
     }
  printf("The transpose of the matrix is\n");
  for(i=0;i<c;i++)
    {for(j=0;j<r;j++)
       printf("%d\t",trans[i][j]);
     printf("\n");
    }
  printf("The diagonal elements are:\n");
  if(r==c)
  {
    for(i=0;i<r;i++)
    {
     for(j=0;j<c;j++)
       {
        if(i==j)
            printf("%d\t",a[i][i]);
       }
    }
    for(i=0;i<r;i++)
        sum=sum+a[i][i];
    printf("\nSum of diagonal elements = %d\n",sum);
  }
  else
     printf("Given matrix is not a square matrix");
  return 0;
}
