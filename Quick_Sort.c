#include<stdio.h>
#include<stdlib.h>
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int partition (int arr[], int l, int pi)
{
    int i, j;
    int pivot = arr[pi];
    i = l-1;
    for(j = l; j<pi; j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
            swap(&arr[j], &arr[i]);
        }
    }
    swap(&arr[i+1], &arr[pi]);
    return i+1;
}

void quickSort(int *arr, int p, int r)
{
    int pi;
    if(p<r)
    {
        pi = partition(arr, p, r);
        quickSort(arr, p, pi-1);
        quickSort(arr, pi+1, r);
    }
}

void print(int *arr, int n)
{
    int i;
    for(i=0; i<n; i++)
        printf("%d ",*(arr+i));
    printf("\n");
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

    quickSort(arr, 0, n-1);

    printf("The sorted (Quick Sort) array is:");
    print (arr, n);ppp
    return 0;
}