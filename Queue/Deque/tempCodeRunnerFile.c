#include<stdio.h>
#include<stdlib.h>

#define N 5
int deque[N];
int f=-1,r=-1;

void enqueue_front()
{
    int x;
    printf("\n f=%d r=%d\n",f,r);
    if((f==0 && r==N-1)||(f=r+1))
    {
        printf("\nOverflow\n");
    
    }
    else
    {
        printf("\n f=%d r=%d\n",f,r);
        printf("Enter a number :");
        scanf("%d",&x);
        printf("\n f=%d r=%d\n",f,r);
        if(r==-1 && f==-1)
        {
            r=0;
            f=0;
            deque[f]=x;
            printf("\n f=%d r=%d\n",f,r);
        }
        else if(f==0)
        {
            f=N-1;
            deque[f]=x;
        }
        else
        {
            f--;
            deque[f]=x;
        }

    }
    
}

void enqueue_rear()
{
    int x;
    printf("\n f=%d r=%d\n",f,r);
    if((f==0&&r==N-1)||(f==r+1))
    {
        printf("Overflow");
        
    }
    else
    {
        printf("Enter a number : ");
        scanf("%d",&x);
        if(r==-1 && f==-1)
        {
            f=0;
            r=0;
            deque[r]=x;
        }
        if(r==N-1)
        {
            r=0;
            deque[0]=x;
        }
        else
        {
            r++;
            deque[r]=x;

        }
    }

}

void display()
{
    int i=f;
    printf("\n f=%d r=%d\n",f,r);
    if(r==-1 && f==-1)
    {
        printf("\nEmpty\n");
        
    }
    else
    {
        while(i!=r)
        {
            printf("%d\n",deque[i]);
            i=(i+1)%N;

        }
        printf("%d",deque[r]);

    }
}

void dequeue_front()
{
    printf("\n f=%d r=%d\n",f,r);
    if(f==-1 && r==-1)
    {
        printf("\nEmpty\n");
        
    }
    else if(f==r)
    {
        printf("dequeue : %d",deque[f]);
        f=-1;
        r=-1;
    }
    else if(f==N-1)
    {
        printf("dequeue : %d",deque[f]);
        f=0;
    }
    else
    {
        printf("dequeue : %d",deque[f]);
        f++;
    }
}

void dequeue_rear()
{
    printf("\n f=%d r=%d\n",f,r);
    if(f==-1&&r==-1)
    {
        printf("Empty\n");
        
    }
    else if(f==r)
    {
        printf("dequeue : %d",deque[r]);
        r=-1;
        f=-1;
    }
    else if(r==0)
    {
        printf("dequeue : %d",deque[r]);
        r=N-1;
    }
    else
    {
        printf("dequeue : %d",deque[r]);
        r--;
    }
    
}


int menu()
{
    int ch;
    printf("\n1.Enqueue Front\n2.Enqueue Rear\n3.Dequeue Front\n4.Dequeue Rear\n5.Display\n6.Exit\n");
    scanf("%d",&ch);
    return(ch);
}

int main()
{
    while(1)
    {
        switch(menu())
        {
            case 1: enqueue_front();
            break;
            case 2: enqueue_rear();
            break;
            case 3: dequeue_front();
            break;
            case 4: dequeue_rear();
            break;
            case 5: display();
            break;
            case 6: exit(0);
            break;
            default: printf("Enter valid option.\n");
            break;
        }
    }
}