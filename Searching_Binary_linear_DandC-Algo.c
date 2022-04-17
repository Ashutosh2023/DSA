#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int b_count=0;
int linear (int *arr, int x, int n)
{
    int i;
    for(i=0; i<n; i++)
        if(arr[i] == x)
            return i;
    return i;
}
// int binary (int *arr, int x, int n)
// {
//     int l, r, mid;
//     l = 0;
//     r = n-1;
//     while (1)
//     {
//         mid = floor((l+r)/2);
//         b_count+=1;
//         if (arr[mid] == x) return mid;             // binary search using normal return.
//         else if (arr[mid] < x) l = mid+1;
//         else if (arr[mid] > x) r = mid-1;
//         else return -1;
//     }
// }
int binary (int *arr, int l, int r, int x)
{
    int b_count = 0;
    if (l<=r)
    {
        b_count++;                                               //binary search using recursion.
        int mid = l + (r - l) / 2;
            if (*(arr + mid) == x)
                return mid;
            else if (*(arr + mid) > x)
                return binary(arr, l, mid - 1, x);
            else
                return binary(arr, mid + 1, r, x);
    }
    return -1;
}
int main()
{
    int n, num, i, result;
    printf("Enter the size of the Array: ");
    scanf("%d",&n);
    int *arr = (int *)malloc(n*sizeof(int));
    for (i = 0; i < n; i++)
        scanf("%d", (arr + i));
    printf("Enter the element to be searched In Binary Search:");
    scanf("%d", &num);
    // result = binary(arr, num, n);
    int l=0, r=n-1;
    result = binary(arr, l, r, num);
    if (result == -1)
        printf("Element is not present in array.\n");
    else
        printf("Element is present at index %d\n", result);
    printf("No. of iterations in the binary search:%d\n", b_count);
    
    //linear search
    printf("\nEnter the number you want to linear search: ");
    scanf("%d",&num);
    result = linear(arr, num, n);
    if (result < n)
    {
        printf("The Element is present at index: %d\n", result);
        printf("No. of iterations in the linear search: %d", result+1);
    }
    else
    {
        printf("Element is not present in the array.\n");
        printf("No. of iteration in the linear search: %d", result);
    } 
}
























// ////Code Example
// #include <stdio.h>
// #include <stdlib.h>
// int b_c = 0;
// int binarySearch(int *arr, int l, int r, int x)
// {
//     b_c++;
//     if (r >= l)
//     {
//         int mid = l + (r - l) / 2;

//         if (*(arr + mid) == x)
//             return mid;

//         if (*(arr + mid) > x)
//             return binarySearch(arr, l, mid - 1, x);

//         return binarySearch(arr, mid + 1, r, x);
//     }
//     return -1;
// }
// int linearsearch(int *arr, int n, int x)
// {
//     int i;
//     for (i = 0; i < n; i++)
//         if (arr[i] == x)
//             return i;
//     return i;
// }
// int main()
// {
//     int n, result, i;
//     printf("Enter the size of array:");
//     scanf("%d", &n);
//     int *arr;
//     arr = (int *)malloc(n * sizeof(int));
//     for (i = 0; i < n; i++)
//         scanf("%d", (arr + i));
//     int x;
//     printf("Enter the element to be searched In Binary Search:");
//     scanf("%d", &x);
//     result = binarySearch(arr, 0, n - 1, x);
//     if (result == -1)
//         printf("Element is not present in array\n");
//     else
//         printf("Element is present at index %d\n", result);
//     printf("No of iterations in the binary search:%d\n", b_c);

//     printf("Enter the element to be searched In Linear Search:");
//     scanf("%d", &x);
//     result = linearsearch(arr, n, x);
//     if (result < n)
//     {
//         printf("Element is present at index %d\n", result);
//         printf("No of iterations in the linear search:%d\n", result + 1);
//     }
//     else
//     {
//         printf("Element is not present in the array\n");
//         printf("No of iterations in the linear search:%d\n", result);
//     }
//     return 0;
// }