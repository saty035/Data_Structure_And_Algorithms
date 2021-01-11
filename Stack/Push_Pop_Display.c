
//using array implementation(ADT)

#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int top;
    unsigned capacity;
    int * array;

};

struct stack* createstack(unsigned capacity)
{
    struct stack* s=(struct stack *)malloc(sizeof(struct stack));
    s->capacity=capacity;
    s->top=-1;
    s->array=(int *)malloc(s->capacity*sizeof(int));
    return s;
}

int push(struct stack *s)
{
    if(s->top==s->capacity-1)
    {
        printf("Stack is Overflow");
        return(0);
    }
    printf("\nEnter the value to push : ");
    int i=s->top;
    scanf("%d",&s->array[i++]);
    s->top=i;
    printf("\nPushed %d",s->top);
    return(0);

}

int pop(struct stack *s)
{
    if(s->top==-1)
    {
        printf("\nstack Underflow");
        return(0);
    }
    int i=s->top;
    printf("\n%d\n",i);
    printf("\nPop value is : %d ",s->array[i]);
    s->top--;
    printf("\n%d\n",s->top);
    return(0);
}

void display(struct stack *s)
{
    int i;
    printf("\nDisplay\n");
    i=s->top;
    printf("\n%d",s->array[i]);
    while(i!=-1)
    {
        printf("\n %d",s->array[i]);
        i--;
    }
}


int menu()
{
    int n;
    printf("\n1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT\n Your Choice : ");
    scanf("%d",&n);
    return(n);
}

int main()
{
    int cap;
    printf("Enter the capacity of the stack : ");
    scanf("%d",&cap);
    struct stack* s=createstack(cap);
    while(1)
    {
        switch(menu())
        {
            case 1: push(s);
            break;
            case 2: pop(s);
            break;
            case 3: display(s);
            break;
            case 4: exit(0);
            break;
            default: printf("\nEnter valid choice ");
            break;
        }
    }
}