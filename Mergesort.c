#include<stdio.h>
void merge(int A[],int p,int q,int r)
{
    int L[20],R[20];
    int n1,n2,i,j,k;
    n1=q-p+1;
    n2=r-q;
    for(i=0;i<n1;i++)
       L[i]=A[p+i];
    for(j=0;j<n2;j++)
       R[j]=A[q+j+1];
    L[i]=10000;
    R[j]=10000;
    i=0;
    j=0;
    for(k=p;k<=r;k++)
    {
       if(L[i]<=R[j])
	  A[k]=L[i++];
       else
	  A[k]=R[j++];
    }
}

void mergesort(int A[],int p,int r)
{
   int q;
   if(p<r)
   {
       q=(p+r)/2;
       mergesort(A,p,q);
       mergesort(A,q+1,r);
       merge(A,p,q,r);
   }
}
int main()
{
    int A[30],i,n;
    printf("Enter Size:");
    scanf("%d",&n);
    printf("Enter Elements:");
    for(i=0;i<n;i++)
      scanf("%d",&A[i]);
    printf("\n Before Sort :");
    for(i=0;i<n;i++)
       printf("\n %d",A[i]);
    mergesort(A,0,n-1);
    printf("\nAfter sort");
    for(i=0;i<n;i++)
      printf("\n %d",A[i]);
}
