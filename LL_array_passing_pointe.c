#include<stdio.h>
void getdata(int *, int);
void show(int *, int);
#define MAX 50

void getdata(int*a, int n)
{
    printf("Enter element one by one");
    int i=0,x;
    for(i=0;i<n;i++)
    {
        scanf("%d",(a+i));
    }
}
void showdata(int* a, int n)
{
    printf("The elements in the array are:");
    int i;
    for(i=0;i<n;i++)
        printf("%d ",*(a+i));
}

main()
{
    int arr[MAX],n,i;
    
    printf("Enter the number of elements you want in the array.");
    scanf("%d",&n);
    getdata(arr,n);
    showdata(arr,n);
}