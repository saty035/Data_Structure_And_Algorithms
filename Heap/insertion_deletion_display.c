#include<stdio.h>
#include<stdlib.h>

//heapify 
int heapify(int A[], int n, int data)
{
    n=n+1;
    int i=n;
    A[n]=data; //storing the data 
    
        while(i!=0)
        {
            if(A[(i-1)/2]<data) // restructuring the heap
            {
                
                int temp=A[(i-1)/2];
                A[(i-1)/2]=A[i];
                A[i]=temp;
                i=(i-1)/2;

                if(i==0)
                {
                    A[i]=data;

                }
            
            }
            else
            {
                i=(i-1)/2;
            }
        }
       
    return(n);
}


//deletion of a particular element from a heap
int delete(int A[],int n, int data)
{
    int j,x;
    if(n==-1)
    {
        printf("\nNothinng to Delete\n");
    }
    else
    {
        for(int i=0;i<=n;i++)
        {
            if(A[i]==data)
            {
                j=i;  // identifying the index
            }
        }
         
        A[j]=A[n];   // storing the last node data
        n=n-1;       // reducing the size by 1
        if(j==n)     // if data is the last node data
        {
            return n;
            
        }
        else
        {
          
            while (1)
            {
                if(A[2*j + 1]>A[2*j +2])    // looking for greater element
                {
                    x=2*j + 1;              
                    int temp=A[j];
                    A[j]=A[2*j + 1];
                    j=2*j +1;

                    if((2*j +1)>n)         //checking for size error
                    {
                        A[x]=temp;
                        return(n);
                    }
                   
                    continue;

                }
                if(A[2*j + 1]<A[2*j +2])   // looking for greater element
                {
                    x=2*j +2;
                    int temp=A[j];
                    A[j]=A[2*j + 2];
                    j=2*j +2;

                    if((2*j +2)>n)         //checking for size error
                    {
                        A[x]=temp;
                        return n;
                    }
                    
                    continue;

                }
            }
            
        }
    }
    
    return n;
}

//menu
int menu()
{
    int ch;
    printf("\n1. Heapify.\n2. Delete.\n3. Display Level Order.\n4. Exit.\n");
    scanf("%d",&ch);
    return ch;
}

//Displaying the heap in Level Order
void Display_Level_Order(int A[],int n)
{
    if(n==-1)
    {
        printf("\nHeap is Empty");
    }
    else
    {
        printf("\nHeap\n");
        for(int i=0;i<=n;i++)
        {
            printf("%d ", A[i]);
        }
    }
}

//main
int main()
{
    int data;
    int del_data;
    int n=-1;
    int size;
    printf("Enter the Size of the heap : ");   // asking for size of the heap
    scanf("%d",&size);
    int A[size];
    while (1)
    {
        switch(menu())
        {
            case 1:                                            //insertion in heap ie. heapify
            printf("Enter data to Heapify : ");
            scanf("%d",&data);
            n=heapify(A,n,data);
            break;

            case 2:                                                 //deletion from the heap
            printf("\nEnter the node to be deleted from heap : ");
            scanf("%d",&del_data);
            n=delete(A,n,del_data);
            break;

            case 3:                                             //displaying the nodes
            Display_Level_Order(A,n);
            break;

            case 4: exit(0);
            break;


            default: printf("\nRe-enter Choice\n");
            break;

        }
    }
    
}