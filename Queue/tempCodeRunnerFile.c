//Array implementation

#include<stdio.h>
#include<stdlib.h>

//Creating Datatype for queue
struct arrayqueue
{
    int rear, front;
    int capacity;
    int *array;
};

//Queue creation
struct arrayqueue * createqueue(int cap)
{
    struct arrayqueue *Q;
    Q=(struct arrayqueue *)malloc(sizeof(struct arrayqueue));
    if(!Q)
    {
        return(NULL);
    }
    Q->capacity=cap;
    Q->front=Q->rear=-1;
    Q->array=malloc(Q->capacity*sizeof(int));
    if(!Q->array)
    {
        return(NULL);
    }
    return(Q);
}

//empty or not
int isempty(struct arrayqueue *Q)
{
    return(Q->front==-1);
}

//full or not
int isfull(struct arrayqueue *Q)
{
    return((Q->rear+1)%Q->capacity==Q->front);
}

int queuesize(struct arrayqueue *Q)
{
    int x=(Q->capacity-Q->front+Q->rear+1)%Q->capacity;
    if(Q->front==-1)
    {
        return(0)
    }
    else if(x==0)
    {
        return(Q->capacity);
    }
    else
    {
        return(x);
    }
    
}


//insertion in queue(LIFO)
int enqueue(struct arrayqueue *Q,int data)
{
    if(isfull(Q))
    {
        printf("Overflow");
        return(0);
    }
    else
    {
        Q->rear=(Q->rear+1)%Q->capacity;
        Q->array[Q->rear]=data;
        if(Q->front==-1)
        {
            Q->front=Q->rear;
        }
    }
    return(0);
    
}

//deleting elements from queue
int dequeue(struct arrayqueue *Q)
{
    int data;
    if(isempty(Q))
    {
        printf("Empty Queue");
        return(0);
    }
    else
    
    {
        data=Q->array[Q->front];
        if(Q->front==Q->rear)
        {
            Q->front=Q->rear=-1;
        }
        else
        {
            Q->front=(Q->front+1)%Q->capacity;
        }

        return(data);
    } 
    

       

}

//deleting the whole queue
void delete(struct arrayqueue *Q)
{
    if(Q)
    {
        if(Q->array)
        {
            free(Q->array);
        }
        free(Q);
    }
}

//menu options
int menu()
{
    printf("\n1.Enqueue\n2.Dequeue\n3.Queue Size\n4.Delete Queue\n");
    int n;
    scanf("%d",&n);
    return(n);
}

int main()
{
    struct arrayqueue *Q;
    int cap,data,x,q;
    printf("Enter the capacity\n");
    scanf("%d",&cap);
    Q=createqueue(cap);
    
    while(1)
    {
        switch (menu())
        {
        case 1: printf("enter the element : ");
                scanf("%d",&data);
                enqueue(Q,data);
            break;
        case 2: x=dequeue(Q);
                if(x==0){ break;}
                printf("\nDequeued element is %d",x);
            break;
        case 3: q=queuesize(Q);
                printf("Queue Size is %d",q);
            break;
        case 4: delete(Q);
                printf("Queue is deleted");
                exit(0);
            break; 
        default: printf("Enter valid input");
            break;
        }
    }
}