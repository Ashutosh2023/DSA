#include<stdio.h>
#include<stdlib.h>
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void print(int *arr, int n)
{
    int i;
    for(i=0; i<n; i++)
        printf("%d ",*(arr+i));
    printf("\n");
}
void Insertion_sort(int *arr, int n)
{
    int i, j;
    for(i = 0; i<n; i++)
        for(j = i; j>=0 && *(arr+j) > *(arr+j+1); j--)
            swap(arr+j, arr+j+1);
}

int main()
{
    int n, i;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int *arr = (int *)malloc(n*sizeof(int));
    for(i=0; i<n; i++)
    {
        printf("Enter Element-%d: ",i+1);
        scanf("%d",arr+i);
    }
    printf("The unsorted array is: ");
    print(arr, n);

    Insertion_sort(arr, n);

    printf("The sorted(Insertion Sort) array is: ");
    print(arr, n);
    return 0;
}