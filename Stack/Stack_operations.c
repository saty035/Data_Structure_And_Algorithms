//Array implementation
#include<stdio.h>
#include<stdlib.h>

#define N 5
 
int push();
int stack[N];
int top=-1;

int push()
{
    int val;
    if(top==(N-1))
    {
        printf("stack Overflowed");
        top++;
        return 0;
    }
    
    top++;
    printf("Enter the number : ");
    scanf("%d",&val);
    stack[top]=val;
        
    return 0;

}

int pop()
{
    if(top==-1)
    {
        printf("Stack is underflowed");
        return 0;
    }

    printf("poped element is : %d",stack[top]);
    top--;
    return 0;
}

int peek()
{
    printf("peek element is %d",stack[top]);
    return 0;
}

int display()
{
    int i;
    if(top==-1)
    {
        printf("Stack is underflowed");
        return 0;
    }
    i=top;
    while(i!=-1)
    {
        printf("%d\n",stack[i]);
        i--;
    }
    return 0;
}

int menu()
{
    int n;
    printf("\n1.push\n2.pop\n3.peek\n4.display\n5.exit\n");
    scanf("%d",&n);
    return(n);
}

int main()
{
    while(1)
    {
        switch (menu())
        {
        case 1: push();
        break;
        case 2: pop();
        break;
        case 3: peek();
        break;
        case 4: display();
        break;
        case 5: exit(0);
        break;
        default:printf("\nqwerty\n");
        break;
        }
    }
}
