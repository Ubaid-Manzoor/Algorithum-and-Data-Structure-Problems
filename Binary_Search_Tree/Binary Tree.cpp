#include<iostream>
#include<time.h>
using namespace std;
struct Node
{
    int Value;
    struct Node *Left;
    struct Node *Right;
    Node(int value)
    {
        Left=NULL;
        Right=NULL;
        Value=value;
    }
//    Node()
//    {
//        cout<<"Constructor Called"<<endl;
//    }
//    ~Node()
//    {
//        cout<<"Destructor Called"<<endl;
//    }
};
class Binary_Tree
{
private:
    struct Node *root;
public:
    Binary_Tree()
    {
        root = NULL;
        cout<<"Constructor Called"<<endl;
    }
    ~Binary_Tree()
    {
        cout<<"Destructor Called"<<endl;
    }
    void Helper_To_Print(struct Node *Current,string indent)
    {
        if(Current != NULL){
        Helper_To_Print(Current->Right,indent + "    ");
        cout<<indent<<Current->Value<<endl;
        Helper_To_Print(Current->Left,indent + "    ");
        }
    }
    void Print_SideWays()
    {
        string indent ="";
        Helper_To_Print(root,indent);
    }
   /* struct Node* Helper_To_Add(struct Node*& Current,int value)
    {
        if(Current == NULL)
        {
           return (new struct Node(value));
        }
        else if(value < Current->Value)
        {
            Current->Left=Helper_To_Add(Current->Left,value);
            return Current;
        }
        else
        {
            Current->Right=Helper_To_Add(Current->Right,value);
            return Current;
        }
    } */
    void Helper_To_Add(struct Node*& Current,int value)
    {
        if(Current == NULL)
           Current = new struct Node(value);
        else if(value < Current->Value)
            Helper_To_Add(Current->Left,value);
        else if(value > Current->Value)
             Helper_To_Add(Current->Right,value);
    }
/*    void Add(int value)
    {
        root = Helper_To_Add(root,value);
    } */
     void Add(int value)
    {
        Helper_To_Add(root,value);
    }
    bool Helper_To_Find(struct Node *Current,int value)
    {
        if(Current == NULL)
            return false;
        else if(Current->Value == value)
            return true;
        else if(value > Current->Value)
            Helper_To_Find(Current->Right,value);
        else
            Helper_To_Find(Current->Left,value);
    }
    void Find(int value)
    {
        if(Helper_To_Find(root,value))
            cout<<"Found"<<endl;
        else
            cout<<"Not Found"<<endl;
    }
    int Min_in_Heap(struct Node *root)
    {
        if(root->Left == NULL)
            return root->Value;
        else
        {
            Min_in_Heap(root->Left);
        }
    }
    void HelperRemove(struct Node*& root,int value)
    {
        if(root == NULL){
            cout<<"BC baag idersa"<<endl;
        }
        else if(value > root->Value)
           HelperRemove(root->Right,value);
        else if(value < root->Value)
           HelperRemove(root->Left,value);
        else
        {
            struct Node *Trash = NULL;
            //CASE 1 LEAF
            if(root->Left == NULL && root->Right == NULL){
                    Trash = root;
                    root = NULL;
            }
            else if(root->Left == NULL)
            {
                //CASE 2 HAVE A RIGTH CHILD
                 Trash = root;
                root = root->Right;
            }
            else if(root->Right == NULL)
            {
                //CASE 3 HAVE A LEFT CHILD
                 Trash = root;
                root = root->Left;
            }
            else
            {
                //CASE 4 BOTH CHILDS
                int Min = Min_in_Heap(root->Right);
                root->Value = Min;
                HelperRemove(root->Right,Min);
            }
            if(Trash != NULL)
            {
                delete Trash;
            }
        }
    }
    void Remove(int value)
    {
        if(root != NULL)
       HelperRemove(root,value);
    }
};
int main()
{
    Binary_Tree Tree;
    for(int i = 0 ; i < 7 ; i++)
    {
        int value;
        cin>>value;
        Tree.Add(value);
    }
    Tree.Print_SideWays();
    Tree.Find(11);
    Tree.Remove(99);
    Tree.Print_SideWays();
    Tree.Remove(5);
    Tree.Print_SideWays();
    Tree.Remove(6);
    Tree.Print_SideWays();
}
