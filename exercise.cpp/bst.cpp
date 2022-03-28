#include<bits/stdc++.h>
using namespace std;
struct node{
    node*lchild;
    int data;
    node*rchild;
}*root=nullptr;
void createpre(int pre[],int n)
{
    node*t;
    root=new node;
    int i=0;
    root->data=pre[i++];
    root->lchild=root->rchild=nullptr;
    stack<node*>st;
    st.push(t);
    node*p=root;
    while(i<n)
    {
        if(pre[i]<p->data)
        {
            t=new node;
            t->data=pre[i++];
            t->lchild=t->rchild=nullptr;
            p->lchild=t;
            st.push(t);
            p=t;


        }
        else
        {
            if(pre[i]>p->data&&pre[i]<(st.top()?st.top()->data:INT_MAX))
            {
                t=new node;
                t->data=pre[i++];
                t->lchild=t->rchild=nullptr;
                p->rchild=t;
                p=t;

            }
            else
            {
                p=st.top();
                st.pop();
            }
        }
    }
}
void create(node*p,int key)
{
    node*t=new node;
    t->data=key;
    t->lchild=t->rchild=nullptr;
    node*q=nullptr;
    if(p==nullptr)
    root=t;
    else
   { while(p)
    {   q=p;
        if(p->data>key)
        p=p->lchild;
      else  if(p->data<key)
        p=p->rchild;
        
    }
    if(q->data>key)
    q->lchild=t;
    else
    q->rchild=t;

}


}
bool search(node*p,int key)
{
    if(!p)
    return false;
    else
    {  while(p)
        {if(p->data<key)
        p=p->rchild;
        else if(p->data>key)
        p=p->lchild;
         else if(p->data==key)
        return true;}
    }
    return false;
}
node* binariinsert(node*p,int key)
{
    if(p==nullptr)
    {
        node*t=new node;
        t->data=key;
        t->lchild=t->rchild=nullptr;
        return t;
    }
    else
    {
        if(key<p->data)
        p->lchild=binariinsert(p->lchild,key);
        else if(key>p->data)
        p->rchild=binariinsert(p->rchild,key);
    }
    return p;
}
void inorder(node*p)
{
    stack<node*>st;
    while(!st.empty()|| p)
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
void inn(node*p)
{
    if(p)
    {
       inn(p->lchild);
       cout<<p->data<<" ";
       inn(p->rchild);
    }
}
bool binarysearch(node*p,int key)
{
    if(p==nullptr)
    return false;
    else{
        if(key<p->data)
        return binarysearch(p->lchild,key);
        else if(key>p->data)
        return binarysearch(p->rchild,key);
        else if(p->data==key)
        return true;;
    }
}
int height(node*p)
{
    if(p==nullptr)
    return 0;
    else
    {
        int x=height(p->lchild);
       int  y=height(p->rchild);
       return x>y?x+1:y+1;

    }
}
node* inpre(node*p)
{
    while(p&&p->rchild)
    p=p->rchild;
    return p;
}
node* insucc(node*p)
{
    while(p&&p->lchild)
    p=p->lchild;
    return p;
}
node*Delete(node*p,int key)
{
    if(p==nullptr)
    return nullptr;
    else if (!p->lchild&&!p->rchild&&p->data==key)
    {
        if(p==root)
        root=nullptr;
        delete p;
        return nullptr;
    }
    else 
    {
        if(key<p->data)
        p->lchild=Delete(p->lchild,key);
        else 
        if(key>p->data)
        p->rchild=Delete(p->rchild,key);
        else if(p->data==key)
        {
            if(height(p->lchild)<height(p->rchild))
            {
                node*q=insucc(p->rchild);
                p->data=q->data;
                p->rchild=Delete(p->rchild,q->data);

            }
            else
            {
                node*q=inpre(p->lchild);
                p->data=q->data;
                p->lchild=Delete(p->lchild,q->data);
            }
        }
    }
    return p;
}
void preorder(node*p)
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


int main()
{
    // root=binariinsert(root,30);
    // binariinsert(root,20);
    // binariinsert(root,40);
    // binariinsert(root,10);
    // binariinsert(root,25);
    // binariinsert(root,35);
    // binariinsert(root,45);
    // binariinsert(root,42);
    // binariinsert(root,43);
    // Delete(root,43);
    int pre[]={30,20,10,15,25,40,50,45};
    createpre(pre,8);
    
    inorder(root);
    cout<<endl;
    preorder(root);
}
