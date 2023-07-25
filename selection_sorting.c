#include<stdio.h>

void read_array(int arr[],int n)
{
    printf("Enter the array elements\n");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
}

void selection_sort(int arr[],int n)
{
    int i,j,min_idx,min=999,temp;
    for(i=0;i<n-1;i++)
    {
        min_idx=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[min_idx]>arr[j])
                min_idx=j;
        }

        if(min_idx!=i)
        {
            temp=arr[min_idx];
            arr[min_idx]=arr[i];
            arr[i]=temp;
        }
    }
}

void display_array(int arr[],int n)
{
    printf("The sorted array is\n");
    for(int i=0;i<n;i++)
        printf("%d",arr[i]);
}

int main()
{
    int n;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    int arr[n];
    read_array(arr,n);
    selection_sort(arr,n);
    display_array(arr,n);
    return 0;
}
