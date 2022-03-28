#include<bits/stdc++.h>
using namespace std;
struct node
{
    node*lchild;
    int data;
    node*rchild;
};
class Tree{
    public:
    node*root;
    Tree(){root=nullptr;}
     Tree(int A[],int n);
     void create();
    void preorder(node *p);
    void inorder(node *p);
    void postorder(node *p);
    void levelorder(node *p);
    int height(node*p);
    int countsumnode(node*p);
    void mirror(node*p);

};
void Tree::create()
{
    // cout<<"enter root value";
    int x;
    cin>>x;
    root=new node;
    root->data=x;
    root->lchild=root->rchild=nullptr;
    queue<node*>q;
    node*p=root;
   
    q.push(root);
    while(!q.empty())
    {
        p=q.front();
        q.pop();

        // cout<<"enter left child value"<<p->data;
        cin>>x;
     
        if(x!=-1)
        {
            node*t=new node;
            t->data=x;
            t->lchild=t->rchild=nullptr;
            p->lchild=t;
            q.push(t);
        }
        // cout<<"enter right child value"<<p->data;
        cin>>x;
        
        if(x!=-1)
        {
            node*t=new node;
            t->data=x;
            t->lchild=t->rchild=nullptr;
            p->rchild=t;
            q.push(t);
        }
        
    }

    
}
Tree::Tree(int A[],int n)
{

    root=new node;
    root->data=A[0];
    root->lchild=root->rchild=nullptr;
    queue<node*>q;
    q.push(root);
    int i=1;
    while(!q.empty())
    {
        node*p=q.front();
        q.pop();
        if(A[i]!=0)
        {
            node*t=new node;
            t->data=A[i++];
            t->lchild=t->rchild=nullptr;
            p->lchild=t;
            q.push(t);
        }
        // if(A[i]==0)
        // i++;
        if(A[i]!=0)
        {
            node*t=new node;
            t->data=A[i++];
            t->lchild=t->rchild=nullptr;
            p->rchild=t;
            q.push(t);
        }
   

    }

   



}
void Tree::inorder(node*p)
{
    if(p)
    {
        inorder(p->lchild);
        cout<<p->data<<" ";
        inorder(p->rchild);

    }
}
void Tree::preorder(node*p)
{
    if(p)
    {
        cout<<p->data<<" ";
        preorder(p->lchild);
        preorder(p->rchild);

    }
}
void Tree::postorder(node*p)
{
    if(p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        cout<<p->data<<" ";

    }
}
void Tree::levelorder(node*p)
{
    cout<<p->data<<" ";
    queue<node*>q;
    q.push(p);
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
int Tree::height(node*p)
{
    if(p==nullptr)
    return 0;
    else
    {
        int x,y;
        x=height(p->lchild);
        y=height(p->rchild);
        return x>y?x+1:y+1;
    }
}
int Tree::countsumnode(node*p)
{
    if(p==nullptr)
    return 0;
    else
    {
        int x,y;
        x=countsumnode(p->lchild);
        y=countsumnode(p->rchild);
       if(!p->lchild&&!p->rchild)
       return x+y+1;
       else
       return x+y;
    }
}
void pree(node*p)
{
    stack<node*>st;
    while(!st.empty()||p)
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

void Tree::mirror(node*p)
{
    if(p->lchild==nullptr&&p->rchild==nullptr)
    return ;
    else
    {
        int x,y;
       mirror(p->lchild);
        mirror(p->rchild);
        swap(p->lchild,p->rchild);
    }
}
void inn(node*p)

{
    stack<node*>st;
    while(!st.empty()||p)
    {
        if(p)
        {
            st.push(p);
            p=p->lchild;
        }
        else
        {
            p=st.top();
            st.pop();
            cout<<p->data<<" ";
            p=p->rchild;
        }
    }
}

int main()
{

// #ifndef ONLINE_JUDGE
//     freopen("intput.txt","r",stdin);
//     freopen("output.txt","w",stdout);
//     #endif
    
    Tree t;
    t.create();

    // t.inorder(t.root);
    inn(t.root);
    cout<<endl;
    // t.mirror(t.root);
    t.preorder(t.root);
    // pree(t.root);
    cout<<endl;
    t.postorder(t.root);
    cout<<endl;
    t.levelorder(t.root);
    cout<<t.height(t.root);
    cout<<t.countsumnode(t.root);
   
   
  
    
}