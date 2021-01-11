//linked list implementation
#include<stdio.h>
#include<stdlib.h>

int N=0;

struct node
{
    int info;
    struct node * link;
};

struct node *START=NULL;

struct node *createnode()
{
    
    struct node *n;
    n=(struct node *)malloc(sizeof(struct node));
    return(n);
}

int push()
{
    struct node *t,*temp;
    if(N==5)
    {
        printf("\nStack Overflowed");
        return 0;
    }
    temp=createnode();
    temp->link=NULL;
    printf("enter the element : ");
    scanf("%d",&temp->info);
    printf("\nqwerww");
    if(START==NULL)
    {
        START=temp;
        
        N++;
    }
    else
    {
        
        temp->link=START;
        START=temp;
       
        N++;
        
    }
    printf("\nqwe");
    return 0;

}

int pop()
{
    if(N==0)
    {
        printf("Stack Underflowed");
        return 0;
    }
    struct node *r;
    printf("Poped element is : %d",START->info);
    r=START;
    START=START->link;
    free(r);
    N--;
    return 0;

}

int display()
{
    struct node *t;
    if(N==0)
    {
        printf("stack Underflowed ");
        return 0;
    }
    t=START;
    printf("\n%d\n\n",t->info);
    while(t!=NULL)
    {
        printf("\n%d",t->info);
        t=t->link;
    }

    return 0;
}

int menu()
{
    int n;
    printf("\n1.push\n2.pop\n3.display\n4.exit");
    scanf("%d",&n);
    return(n);
}

int main()
{
    while(1)
    {
        switch(menu())
        {
            case 1: push();
            break;
            case 2: pop();
            break;
            case 3: display();
            break;
            case 4: exit(0);
            break;
            default : printf("Invalid entry ");
            break;
        }
        
    }
}