#include<stdio.h>
#include<string.h>

int main()
{
    int i, n = 1,x =0;
    char A[25],B[25];
    char C[50] = "  ";
    printf("Enter String A: ");
    scanf("%s",A);
    printf("Enter String B: ");
    scanf("%s",B);
    if(strlen(A)>strlen(B))
    {
     x = strlen(B);
    }
    else
    {
    x = strlen(A);
    }
   for ( i = 0; i < x; i++)
    {
      C [n]= A[i];
      n++;
      C [n]+= B[i];
      n++;
    }
    if(strlen(A)>strlen(B))
    {
        while (i < strlen(A))
        {
            C[n] = A[i];
            i++;
            n++;
        }
    }
    else
    {
        while (i < strlen(B))
        {
            C[n] = B[i];
            i++;
            n++;
        }
    }
    printf("The Concatenation of Strings A and B is: %s\n",C);
    return 0;
}
