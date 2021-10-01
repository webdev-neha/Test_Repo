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
int search(int inorder[],int start,int end,int curr)
{
    for(int i=start;i<=end;i++)
    {
        if(inorder[i]==curr)
        {
            return i;
        }
    }
    return -1;
}
Node* buildtree(int inorder[],int postorder[],int start,int end)
{
    static int idx=end;
    if (start>end)
    {
        return NULL;
    }
    int curr=postorder[idx];
    idx--;
    Node *n=new Node(curr);
    if(start == end)
    {
        return n;
    }
    int pos=search(inorder,start,end,curr);
    n->right=buildtree(inorder,postorder,pos+1,end);
    n->left=buildtree(inorder,postorder,start,pos-1);
    return n;
}
void inorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    int n=7;
    int in[n]={4,2,5,1,6,3,7};
    int post[n]={4,5,2,6,7,3,1};

    Node* root=buildtree(in,post,0,n-1);
    inorder(root);
    return 0;
}