#include<stdio.h>
#define MAX 100
int cost=0;
int reversals=0;
//Reverse elements from i to j
void reverse(int a[],int i,int j)
{
    int temp;
    cost+=j-i+1;
    reversals++;

    while(i<j)
    {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        i++;
        j--;
    }
}
//Partition using divide and conquer
int partition(int a[],int l,int r,int value)
{
    if(l==r)
    {
        if(a[l]<=value)
            return l+1;
        return l;
    }

    int mid=(l+r)/2;

    int p1=partition(a,l,mid,value);
    int p2=partition(a,mid+1,r,value);

    //Left part: True False
    //Right part: True False
    //Rotate False and True parts

    reverse(a,p1,mid);
    reverse(a,mid+1,p2-1);
    reverse(a,p1,p2-1);

    return p1+(p2-(mid+1));
}
//Divide and conquer sorting
void sort(int a[],int l,int r,int low,int high)
{
    if(l>=r || low>=high)
        return;

    int value=(low+high)/2;

    //Partition elements based on middle value
    int p=partition(a,l,r,value);

    //Sort left part
    sort(a,l,p-1,low,value);

    //Sort right part
    sort(a,p,r,value+1,high);
}
int main()
{
    int a[MAX];
    int n,i;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter permutation:\n");

    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    sort(a,0,n-1,1,n);

    printf("Sorted permutation:\n");

    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    printf("\nTotal reversals = %d",reversals);
    printf("\nTotal reversal cost = %d\n",cost);
    return 0;
}