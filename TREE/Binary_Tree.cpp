#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        node *left;
        node *right;
    
    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
node* create_BT( node *root)
{
    int data;
    cout<<"enter the data"<<endl;
    cin>>data;
    if(data==-1) return NULL;

    root = new node(data);

    cout<<"enter the data to be inserted in left"<<endl;
    root->left=create_BT(root->left);
    cout<<"enter the data to be inserted in right"<<endl;
    root->right=create_BT(root->right);

}
void level_order(node * root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp==NULL)
        {
            cout<<endl;
             if(!q.empty()) { 
                q.push(NULL);
            }  
        }
        else {
            cout<<temp->data<<" ";
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
void Inorder(node *root)
{
    //LNR
    if(root==NULL) return ;

    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right); 
}
void Preorder(node *root)
{
    //NLR
    if(root==NULL) return ;

    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right); 
}
void Postorder(node *root)
{
    //LRN
    if(root==NULL) return ;
    
    Postorder(root->left);
    Postorder(root->right); 
    cout<<root->data<<" ";
}
int main()
{
    node *root=NULL;

    root =create_BT(root);
    cout<<"\nlevel order traversal"<<endl;
    level_order(root);
    cout<<"\nInorder traversal"<<endl;
    Inorder(root);
    cout<<"\npreorder traversal"<<endl;
    Preorder(root);
    cout<<"\npostorder traversal"<<endl;
    Postorder(root);
}