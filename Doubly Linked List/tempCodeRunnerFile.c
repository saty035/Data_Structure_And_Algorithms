#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *prev,*next;
};
struct node *START=NULL;
struct node *createnode()
{
    struct node *n;
    n=(struct node *)malloc(sizeof(struct node));
    return(n);
};

int insertnode()
{
    int n;
    struct node *temp,*t;
    temp=createnode();
    printf("\nEnter a number : ");
    scanf("%d",&temp->info);
   
    temp->next=NULL;
    temp->prev=NULL;
    if(START==NULL)
    {
        START=temp;
        return(0);
    }
    printf("\nEnter the position : ");
    scanf("%d",&n);
    if(n==1)
    {
        t=START;
        START=temp;
        t->prev=temp;
        temp->next=t;
    }
    else if(n>1)
    {
        t=START;
        for(int i=1;i<(n-1);i++)
        {
            t=t->next;
        }
        if(t->next==NULL)
        {
            t->next=temp;
            temp->prev=t;
        }
        else
        {
            temp->next=t->next;
            t->next->prev=temp;
            t->next=temp;
            temp->prev=t;
        }
    }
    return(0);
}

int display()
{
    struct node *t;
    if(START==NULL)
    {
        printf("Doubly linked list is empty.");
        return(0);
    }
    t=START;
    while(t!=NULL)
    {
        printf("\n%d",t->info);
        t=t->next;
    }
    return(0);
}

int delete()
{
    struct  node *t,*r;
    int n;
    if(START==NULL)
    {
        printf("Doubly linked is empty.");
        return(0);
    }
    printf("\nEnter index for deletion : ");
    scanf("%d",&n);
    if(n==1)
    {
        if(START->next==NULL)
        {
            t=START;
            START=NULL;
            free(t);
        }
        else
        {
            t=START;
            START=START->next;
            START->prev=NULL;
            free(t);
        }
        
    }
    else
    {
        t=START;
        r=START->next;
        for(int i=0;i<(n-2);i++)
        {
            t=t->next;
            r=r->next;
        }
        if(r->next==NULL)
        {
            t->next=NULL;
            free(r);
        }
        else
        {
            t->next=r->next;
            r->next->prev=t;
            free(r);
        }
            
        
        
    }
    return(0);
}


int reverse()
{
    struct node *t,*temp;
    if(START==NULL)
    {
        printf("\nDoubly Linked List is empty.");
        return(0);
    }
    t=START;
    while (1)
    {
        temp=t->prev;
        t->prev=t->next;
        t->next=temp;
        if(t->prev!=NULL)
        {
            t=t->prev;
        }
        else
        {
            break;
        }
        
    }
    START=t;
    printf("\nDoubly linked list is reversed.\n");
    

}


int viewlist()
{
    struct node *t;
    int n;
    if(START==NULL)
    {
        printf("\nDoubly linked list is empty\n");
        return(0);
    }
    printf("Enter the number of node : ");
    scanf("%d",&n);
    t=START;
    for(int i=0;i<(n-1);i++)
    {
        t=t->next;

    }
    printf("The %d node id %d : ",n,t->info);
}

int menu()
{
    int n;
    printf("\n0.Exit.\n1.Insertion.\n2.Display\n3.Delete\n4.Viewlist\n5.Reverse\nEnter a choice : ");
    scanf("%d",&n);
    return(n);
}

int main()
{
    while(1)
    {
        switch (menu())
        {
        case 1: insertnode();
            break;
        case 2: display();
            break;
        case 3: delete();
            break;
        case 4: viewlist();
            break;
        case 5: reverse();
            break;
        case 0: exit(0);
            break;
        default: printf("\nEnter a valid choice.\n");
            break;
        }
    }
    return(0);
}

