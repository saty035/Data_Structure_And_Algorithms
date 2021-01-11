#include<stdio.h>
#include<stdlib.h>

//structure of binary search tree
struct bstnode
{
    int data;
    struct bstnode *left;
    struct bstnode *right;
};

//insertion in binary search tree
struct bstnode * insert(struct bstnode *root,int data)
{
    struct bstnode *par;

    //memory allocation
    struct bstnode *n=malloc(sizeof(struct bstnode));

    //assigning intial values
    n->data=data;
    n->left=NULL;
    n->right=NULL;

    //checking the condition for root
    if(root==NULL) //if root is NULL
    {
        root=n;
    }
    else //if root has some value
    {
        par=root;
        while(par!=NULL)
        {
            if(par->data>data) //placing the data
            {
                if(par->left==NULL)
                {
                    par->left=n;
                    return(0);
                }
                
                
                    par=par->left;
                
            }
            else if(par->data<data) //placing the data
            {
                if(par->right==NULL)
                {
                    par->right=n;
                    return(0);
                }
                    par=par->right;
            }
        }
    }
}

//finding the maximum in the subtree
struct bstnode * findmax(struct bstnode *root)
{
    do{
        if(root->right==NULL)
        {
            return(root);
        }
        root=root->right;
    }while(root->right!=NULL);
    
}

//deletion of a node
struct bstnode * delete(struct bstnode *root,int data)
{
    struct bstnode *temp;

    //checking the condition
    if(root==NULL)
    {
        printf("\n\nno such element exists\n\n");
    }
    else if(root->data>data)
    {
        root->left=delete(root->left,data); //recursion for reaching the element
    }
    else if(root->data<data)
    {
        root->right=delete(root->right,data); //recursion for reaching the element
    }

    else //element found
    {
        if(root->left!=NULL && root->right!=NULL) //two children
        {
            temp=findmax(root->left); //it will be in the left 
            root->data=temp->data; //assigning the data
            root->left=delete(root->left,root->data);
        }
        else //one or none child
        {
            temp=root;
            if(root->left==NULL)
            {
                root=root->right;
            }
            else
            {
                root=root->left;
            }
            free(temp); //releasing the memory
        }
    }
    return(root);
}



//finding the element in the tree
struct bstnode * find(struct bstnode *root,int data)
{
    if(root==NULL)
    {
        return(0);
    }
    if(data<root->data)
    {
        return(find(root->left,data));
    }
    if(data>root->data)
    {
        return(find(root->right,data));
    }
    return(root);
}


//menu
int menu()
{
    int ch;
    printf("\n1.Insertion\n2.Deletion\n3.Find\n4.Inorder Traversal\n5.level order traversal\n6.Exit\n");
    scanf("%d",&ch);
    return(ch);
}

//inorder traversal
void inorder(struct bstnode *root)
{
    if(root)
    {
        inorder(root->left);
        printf(" %d \t",root->data);
        inorder(root->right);
    }
}


//level order traversal
int levelorder(struct bstnode *root,int size)
{
    
    struct bstnode *temp;
    struct bstnode *arr[10]; //queue of bstnode datatype
    int front=-1,rear=0,x=0;
    if(!root)
    {
        return(0);
    }
    arr[0]=root;

    while(x!=(size))
    {
        front++;
        temp=arr[front];
        printf(" %d ",temp->data);
        x++;
        if(temp->left)
        {
            rear++;
            arr[rear]=temp->left;
        }
        if(temp->right)
        {
            rear++;
            arr[rear]=temp->right;
        }
        
    }
}


//main 
int main()
{
    struct bstnode *root,*x;
    root=NULL;
    int data,i=0,size=0;
  
     
    while(1)
    { 
        //switch case
        switch (menu())
        {
        case 1: printf("\nEnter the element to be inserted in the BST : ");
                scanf("%d",&data);
                i++;
                
                if(i==1)
                {
                    root=insert(root,data);
                }
                else
                {
                    insert(root,data);
                }
                size++;
                break;
                
        case 2: printf("\nEnter the element to be deleted in the BST : ");
                scanf("%d",&data);
                delete(root,data);
                printf("\n%d is deleted from the tree\n",data);
                size--;
                break;
        case 3: printf("\nEnter the element to find in the BST : ");
                scanf("%d",&data);
                x=find(root,data);
                if(x==NULL)
                {
                    printf("\nNULL\n");
                    break;
                }

                printf("%d found",x->data);
                break;
        case 4: inorder(root);
                break;
        case 5: levelorder(root,size);
                break;
        case 6: printf("\nEXIT\n");
                exit(1);
                break;
        default: printf("\n\nEnter a valid choice\n\n");
            break;
        }
    }
}