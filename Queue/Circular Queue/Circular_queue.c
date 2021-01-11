//Linked List Implementation

#include<stdio.h>
#include<stdlib.h>

//creating data type
struct node
{
    int info;
    struct node * link;
};

//memory alocation
struct node * createnode()
{
    struct node * n;
    n=(struct node *)malloc(sizeof(struct node));
    return(n);
}

struct node *START=NULL;

//inserting in the end of circular linked list
void enqueue()
{
    struct node *temp,*t;
    temp=createnode();
    printf("Enter the element : ");
    scanf("%d",&temp->info);
    temp->link=NULL;
    if(START==NULL)
    {
        START=temp;
        temp->link=START;
    }
    else
    {
        t=START;
        while(t->link!=START)
        {
            t=t->link;
        }
        t->link=temp;
        temp->link=START;
    }
    
    
}

//deletion from the begining
int dequeue()
{
    struct node *t,*r;
    if(START==NULL)
    {
        printf("Queue is Empty");
        return(0);
    }
    else if(START->link==START)
    {
        t=START;
        printf("Dequeue element is : %d",t->info);
        START=NULL;
        free(t);

    }
    else
    {
        t=START;
        printf("Dequeue element is : %d",t->info);
        r=START;
        while(r->link!=START)
        {
            r=r->link;
        }
        r->link=t->link;
        START=START->link;
        free(t);
        return(0);

    }
    
}

//Queue size
int queuesize()
{
    int i=1;
    struct node *t;
    t=START;
    if(START==NULL)
    {
        return(0);
    }
    else
    {
        while(t->link!=START)
        {
            t=t->link;
            i++;
        }
        return(i);

    }
    
}

//emnu options
int menu()
{
    int ch;
    printf("\n1.EnQueue\n2.DeQueue\n3.Queue Size\n4.Exit\n");
    scanf("%d",&ch);
    return(ch);
}

//main
int main()
{
    int x;
    while(1)
    {
        switch(menu())
        {
            case 1: enqueue();
            break;
            case 2: dequeue();
            break;
            case 3: x=queuesize();
            printf("Queue Size id %d",x);
            break;
            case 4: exit(0);
            break;
            default: printf("Enter vaild input \n");
            break;
        }
    }
}