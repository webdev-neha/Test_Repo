#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

bool checkbst(Node* root,int &min,int &max)
{
    if(root==NULL)
    {
        return true;
    }
    if(root->left!=NULL && root->data<min)
    {
        return false;
    }
    if(root->right!=NULL && root->data>max)
    {
        return false;
    }

    bool left=checkbst(root->left,min,root->data);
    bool right=checkbst(root->right,root->data,max);

    return left && right;
}
Node* insertbst(Node* root,int val)
{
    if(root==NULL)
    {
        return new Node(val);
    }
    if(root->data>val)
    {
        root->left=insertbst(root->left,val);
    }
    else
    {
        root->right=insertbst(root->right,val);
    }
    return root;
}
int main()
{
    Node* root=NULL;
    root=insertbst(root,5);
    insertbst(root,1);
    insertbst(root,3);
    insertbst(root,4);
    insertbst(root,2);
    insertbst(root,7);

    int min=INT_MIN;
    int max=INT_MAX;
    cout<<checkbst(root,min,max);
    return 0;
}