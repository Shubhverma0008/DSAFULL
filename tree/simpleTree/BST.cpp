#include <iostream>

using namespace std;
struct node
{
    node *lchild;
    int data;
    node *rchild;

} *root = nullptr;
int height(node*p)
{
    int x,y;
    if(p==nullptr)
    return 0;
    else
    {
        x=height(p->lchild);
        y=height(p->rchild);
        return x>y?x+1:y+1;
    }
}
node *inpredecer(node*p)
{
    while(p&&p->rchild)
    {
        p=p->rchild;
    }
    return p;

}
node*insucc(node*p)
{
    while(p&&p->lchild)
    {
        p=p->lchild;
    }
    return p;
}





node*Delete(node*p,int key)
{  node*q;
    if(p==nullptr)
    return nullptr;
    if(!p->lchild&&!p->rchild&&p->data==key)
    {
        if(p==root)
        root=nullptr;
        delete p;
        return nullptr;
    }
    if(p->data>key)
    p->lchild=Delete(p->lchild,key);
    else if(p->data<key)
    p->rchild=Delete(p->rchild,key);
    else if(p->data==key)
    {
        if(height(p->lchild)>height(p->rchild))
        {
            q=inpredecer(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        }
        else
        {
            q=insucc(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
        }
    }
    return p;
}

node* binarysearch(node *p,int key)
{
    if(p==nullptr)
    return nullptr;
    else 
    {
        if(p->data>key)
        return binarysearch(p->lchild,key);
        else if(p->data<key)
        return binarysearch(p->rchild,key);
        else if(p->data==key)
        return p;
    }
}
void preorder(node*p)
{
    if(p)
    {
        cout<<p->data<<" ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void inorder(node*p)
{
    if(p)
    {
        inorder(p->lchild);
        cout<<p->data<<" ";
        inorder(p->rchild);
    }
}
node* binaryinsert(node*p,int key)
{
    if(p==nullptr)
    {
        node*t=new node;
        t->data=key;
        t->lchild=t->rchild=nullptr;
        return t;
    }
    if(p->data>key)
    p->lchild=binaryinsert(p->lchild,key);
   else if(p->data<key)
    p->rchild=binaryinsert(p->rchild,key);
    return p;
}
void insert(node *p, int x)
{
    node *r = nullptr;
    node *t = new node;
    if (p == nullptr)
    {
        t->data = x;
        t->lchild = t->rchild = nullptr;
        root = t;
    }
    else
    {
        while (p)
        {
            r = p;
            if (p->data > x)
                p = p->lchild;
            else if (p->data < x)
                p = p->rchild;
        }
        t->data = x;
        t->rchild = t->lchild = nullptr;
        if (r->data > x)
            r->lchild = t;
        else
            r->rchild = t;
    }
}
node *search(node*p,int key)
{
    if(p==nullptr)
    return nullptr;
    while(p)
    {
        if(p->data>key)
        p=p->lchild;
        else if(p->data<key)
        p=p->rchild;
        if(p->data==key)
        return p;
    }
}
int main()
{
    // root =binaryinsert(root,30);
    // binaryinsert(root,20);
    // binaryinsert(root,40);
    // binaryinsert(root,10);
    // binaryinsert(root,25);
    // binaryinsert(root,35);
    // binaryinsert(root,45);
    // binaryinsert(root,42);
    // binaryinsert(root,43);
    // Delete(root,26);
    
    preorder(root);
    cout<<endl;
    inorder(root);
}