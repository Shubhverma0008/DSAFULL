#include <iostream>
#include<algorithm>
#include <stack>
#include <queue>
using namespace std;
 
struct node
{
    node *lchild;
    int data;
    node *rchild;
};
class Tree
{
public:
    node *root;

public:
    Tree(int A[],int n);
    void preorder(node *p);
    void inorder(node *p);
    void postorder(node *p);
    void levelorder(node *p);
    int height(node*p);
    int countsumnode(node*p);
    void mirror(node*p);
};
void Tree::mirror(node*p)
{
    if(p->lchild==nullptr&&p->rchild==nullptr)
    return ;
    else
    {
        mirror(p->lchild);
        mirror(p->rchild);
        swap(p->lchild,p->rchild);
    }
}
int Tree::countsumnode(node*p)
{
    int x,y;
    if(p==nullptr)
    return 0;
    else
    {
        x=countsumnode(p->lchild);
        y=countsumnode(p->rchild);
        return x+y+p->data;
    }
}
int Tree::height(node*p)
{  int x,y;
    if(p==nullptr)
    return 0;
    x=height(p->lchild);
    y=height(p->rchild);
    return x>y?x+1:y+1;

}
void Tree::levelorder(node*p)
{   queue<node*>q;
    cout<<p->data<<" ";
    q.push(root);
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        if(p->lchild)
        {
            cout<<p->lchild->data<<" ";
            q.push(p->lchild);
        }
        if(p->rchild)
        {
            cout<<p->rchild->data<<" ";
            q.push(p->rchild);
        }
    }

}
void Tree::preorder(node*p)
{
    stack<node*>st;
    while(p||!st.empty())
    {
        if(p)
        {
            cout<<p->data<<" ";
            st.push(p);
            p=p->lchild;
        }
        else
        {
            p=st.top();
            st.pop();
            p=p->rchild;
        }
    }
}
Tree::Tree(int A[],int n)
{
    int x;
    queue<node *> q;
    node *p;
    
    root = new node;
    root->data = A[0];
    root->lchild = root->rchild = nullptr;
    q.push(root);
    int i=1;
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        if(A[i]==0)
        break;
        
        
        if (A[i]>0){
            node *t = new node;
            t->data = A[i++];
            t->lchild = t->rchild = nullptr;
            p->lchild = t;
            q.push(t);

        }
        
         if(A[i]<0)i++;
        if (A[i]>0)
        {
            node *t = new node;
            t->data = A[i];
            t->lchild = t->rchild = nullptr;
            p->rchild = t;
            q.push(t);
        }
        if(A[i]<0)i++;

    }
}
void Tree::postorder(node *p)
{
    if (p)
    {
        postorder(p->lchild);

        postorder(p->rchild);
        cout << p->data << " ";
    }
}
void Tree::inorder(node *p)
{
    stack<node *> st;
    while (p || !st.empty())
    {
        if (p)
        {
            st.push(p);
            p = p->lchild;
        }

        else
        {
            p = st.top();
            st.pop();
            cout << p->data << " ";
            p = p->rchild;
        }
    }
}
  
int main()
{ int A[]={1,2,3,4,5,6,7,0};
    Tree t(A,8);
    // t.mirror(t.root); 
    t.inorder(t.root);
    cout<<endl;
    t.postorder(t.root);
    cout<<endl;
    t.preorder(t.root);
   
    

}