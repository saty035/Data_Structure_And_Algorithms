#include<stdio.h>
#include<stdlib.h>

void swap(int *x,int *y)
{
    int t;
    t=*x;
    *x=*y;
    *y=t;
}

int main()
{
    int x;
    printf("Enter size of array : ");
    scanf("%d",&x);
    int arr[x];
    printf("Enter the elements \n");
    for(int i=0;i<x;i++)
    {
        printf("%dst element : ",i);
        scanf("%d",&arr[i]);
    }
    printf("*****Sorted Array*****");
    for(int i=0;i<x-1;i++)
    {
        for(int j=0;j<x-1;j++)
        {
            if(arr[i]>arr[i+1])
            {
                swap(&arr[i],&arr[i+1])