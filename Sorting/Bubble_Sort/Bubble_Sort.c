//Bubble Sort
#include<stdio.h>
#include<stdlib.h>

//swapping function
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
        printf("%dst element : ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("\n\n*****Sorted Array*****\n");

    for(int i=0;i<x-1;i++)    //first loop
    {
        for(int j=0;j<x-1;j++)    //second loop
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]); //calling swap function
            }
            else
            {
                continue;
            }
            
        }
    }
    for(int i=0;i<x;i++)
    {
        printf("\n %d st element : %d",i+1,arr[i]);   //output after sorting
        
    }


}