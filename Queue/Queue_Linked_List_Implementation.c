//Linked list Immplementation
#include<stdio.h>
#include<stdlib.h>

//new datatype
struct node
{
    int info;
    struct node *link;
};

//allocating memory
struct node * createnode()
{
    struct node *n;
    n=(struct node *)malloc(sizeof(struct node));
    return(n);
}


struct node *START=NULL;


//insertion at the end
int enqueue()
{
    struct node *temp,*t;
    temp=createnode();
    printf("Enter the element :");
    scanf("%d",&temp->info);
    temp->link=NULL;
    if(START==NULL)
    {
        START=temp;
        
    }
    else
    {
        t=START;
        while(t->link!=NULL)
        {
            t=t->link;
        }
        t->link=temp;
    }

    return(0);

}

//deletion from the begining
int dequeue()
{
    struct node *t;
    if(START==NULL)
    {
        printf("Queue is Empty ");

    }
    else
    {
        t=START;
        printf("Dequeue element : %d",t->info);
        START=START->link;
        free(t);
    }
    return(0);
}

//size of the  linked list
int queuesize()
{
    int i=0;
    struct node * t;
    if(START==NULL)
    {
        
        
    }
    else
    {
        t=START;
        while(t!=NULL)
        {
            t=t->link;
            i++;
        }
        


    }
    return(i);
}

//releasing the memory
void deletequeue()
{
    struct node *t,*r;
    t=START;
    r=START;
    while(t!=NULL)
    {
        r=t;
        t=t->link;
        free(r);

    }
    printf("Queue is deleted.");
}

//menu options
int menu()
{
    int ch;
    printf("\n1.Enqueue\n2.Dequeue\n3.Queue Size\n4.Delete Queue\n");
    scanf("%d",&ch);
    return(ch);
}


//main 
int main()
{
    int num;
    while(1)
    {
        switch(menu())
        {
            case 1: enqueue();
            break;
            case 2: dequeue();
            break;
            case 3: num=queuesize();
                    printf("Queue Size is : %d",num);
            break;
            case 4: deletequeue();
            exit(0);
            break;
            default: printf("Enter valid Option \n");
            break;
        }
    }
}