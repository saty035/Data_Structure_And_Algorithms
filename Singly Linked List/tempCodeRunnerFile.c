#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int info;
    struct node *link;
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
    struct node *temp, *t,*r;
    temp=createnode();
    printf("Enter a number : ");
    scanf("%d",&temp->info);
    temp->link=NULL;
    if(START==NULL)
    {
        START=temp;
        return(0);
    }
    printf("\nEnter the position: ");
    scanf("%d",&n);
    if(n==1)
    {
        t=START;
        START=temp;
        temp->link=t;
    }
    else
    {
        t=START;
        r=START->link;
        for(int i=1;i<(n-1);i++)
        {
            t=t->link;
            r=r->link;
        }
        if(r==NULL)
        {
            t->link=temp;
        }
        else
        {
            temp->link=r;
            t->link=temp;
        }
        
    }
    return(0);
}
int delete()
{
    struct node *t, *r;
    int x;
    if(START==NULL)
    {
        printf("Linked List is empty.");
        return(0);
    }
    printf("\nEnter the node to be deleted.");
    scanf("%d",&x);
    if(x==1)
    {
        t=START;
        START=START->link;
        free(t);
    }
    else
    {
        t=START;
        r=START->link;
        for(int i=1;i<(x-1);i++)
        {
            t=t->link;
            r=r->link;
        }
        if(r->link==NULL)
        {
            t->link=NULL;
            free(r);
        }
        else
        {
            t->link=r->link;
            free(r);
        }
        
    }
    printf("\nElement is deleted.\n");
    return(0);
    

}

void display()
{
    struct node *t;
    if(START==NULL)
    {
        printf("Linked List is empty.");
    }
    else
    {
        printf("*****DISPLAY*****\n");
        t=START;
        int i=0;
        while (t!=NULL)
        {
            i++;
            printf("%d. %d \n",i,t->info);
            t=t->link;
        }
        
    }
    
}

int viewlist()
{
    int n;
    struct node *t;
    if(START==NULL)
    {
        printf("\nLinked list is empty.");
        return(0);
    }
    printf("\nEnter the number of node : ");
    scanf("%d",&n);
    t=START;
    for(int i=0;i<(n-1);i++)
    {
        t=t->link;
    }
    printf("\nThe %d node is %d",n,t->info);
    return(0);
}

int reverse()
{
    struct node *cur,*pre;
    if(START!=NULL)
    {
        pre=START;
        cur=START->link;
        START=START->link;

        pre->link=NULL;

        while(START!=NULL)
        {
            START=START->link;
            cur->link=pre;
            pre=cur;
            cur=START;
        }
        START=pre;
        printf("\nREVERSD\n");
        return(0);
    }
}


int menu()
{
    int ch;
    printf("\n0.Exit");
    printf("\n1.Insertion");
    printf("\n2.Display.");
    printf("\n3.Deletion.");
    printf("\n4.Viewlist.");
    printf("\n5.Reverse.\n");
    
    scanf("%d",&ch);
    return(ch);
}

int main()
{
    while(1)
    {
        switch(menu())
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
            default: printf("\nRe-enter Choice.\n");


        }
    }
}