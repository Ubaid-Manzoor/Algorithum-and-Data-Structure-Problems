#include<stdio.h>
//#include<conio.h>
struct node
{
    int key;
    struct node *left;
    struct node *right;
};
struct node* Newnode(int data)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->left =temp->right =NULL;
    temp->key=data;
    return temp;
}
struct node* insert(struct node *root,int data)
{
    if(root==NULL)
    {
        root=Newnode(data);
        return root;
    }
    else if(data <= root->key)
    {
        root->left=insert(root->left,data);
        return root;
    }
    else if(data > root->key)
    {
        root->right=insert(root->right,data);
        return root;
    }
}
struct node* Findmax(struct node *root)
{
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root;
}
struct node* deletion(struct node *root,int data)
{
    if(root==NULL)
    {
        return root;
    }
    else if(data < root->key)
    {
        root->left=deletion(root->left,data);
        return root;
    }
    else if(data > root->key)
    {
        root->right=deletion(root->right,data);
        return root;
    }
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            root =NULL;
            return root;
        }
        else if(root->left==NULL)
        {
            struct node *temp=root->right;
            free(root);
            root=temp;
            return root;
        }
        else if(root->right==NULL)
        {
            struct node *temp=root->left;
            free(root);
            root=temp;
            return root;
        }
        else
        {
            struct node *temp=Findmax(root->left);
            root->key=temp->key;
            root->left=deletion(root->left,root->key);
            return root;
        }
    }
}
void display(struct node *root)
{
    if(root!=NULL)
    {
        display(root->left);
        printf("%d ",root->key);
        display(root->right);
    }
}
void main()
{
    int n,i,data,d;
    struct node *root=NULL;
    printf("enter the number of nodes\n");
    scanf("%d",&n);
    printf("enter the nodes one by one\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&data);
        root=insert(root,data);
    }
    display(root);
    printf("enter the number to delete\n");
    scanf("%d",&d);
    root=deletion(root,d);
    display(root);
    printf("enter the number to delete\n");
    scanf("%d",&d);
    root=deletion(root,d);
    display(root);
    printf("enter the number to delete\n");
    scanf("%d",&d);
    root=deletion(root,d);
    display(root);
    printf("enter the number to delete\n");
    scanf("%d",&d);
    root=deletion(root,d);
    display(root);
}
