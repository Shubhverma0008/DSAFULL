#include <iostream>
using namespace std;
struct node
{
    node *lchild;
    int data;
    int height;
    node *rchild;

} *root = nullptr;
void inorder(node *p)
{
    if (p)
    {
        inorder(p->lchild);
        cout << p->data << " ";
        inorder(p->rchild);
    }
}
void preorder(node *p)
{
    if (p)
    {
        cout << p->data << " ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
int height(node *p)
{
    int x, y;
    if (p == nullptr)
        return 0;
    x = height(p->lchild);
    y = height(p->rchild);
    return x > y ? x + 1 : y + 1;
}
// int height(node *p)
// {
//     int hl, hr;
//     hl = p && p->lchild ? p->lchild->height : 0;
//     hr = p && p->rchild ? p->rchild->height : 0;
//     return hl > hr ? hl + 1 : hr + 1;
// }
int balancefactor(node *p)
{
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;
    return hl - hr;
}
node* LLroataion(node*p)
{
    node*pl=p->lchild;
    node*plr=pl->rchild;
    pl->rchild=p;
    p->lchild=plr;
    pl->height=height(pl);
    p->height=height(p);
    if(root==p)
    root=pl;
    return pl;
}
node* LRroataion(node*p)
{
    node*pl=p->lchild;
    node*plr=pl->rchild;
    node*plrl=plr->lchild;
    node*plrr=plr->rchild;
    plr->lchild=pl;
    plr->rchild=p;
    p->lchild=plrr;
    pl->rchild=plrl;
    p->height=height(p);
    plr->height=height(plr);
    pl->height=height(pl);
    if(p==root)
    root=plr;
    return plr;

}
node* RLroataion(node*p)
{
    node*pr=p->rchild;
    node*prl=pr->lchild;
    node*prlr=prl->rchild;
    node*prll=prl->lchild;
    prl->lchild=p;
    prl->rchild=pr;
    pr->lchild=prlr;
    p->rchild=prll;
    prl->height=height(prl);
    p->height=height(p);
    pr->height=height(pr);
    if(p==root)
    root=prl;
    return prl;



}
node* RRroataion(node*p)
{

node*pr=p->rchild;
node*prl=pr->lchild;
pr->lchild=p;
p->rchild=prl;
pr->height=height(pr);
p->height=height(p);
if(root==p)
root=pr;
return pr;
}
node *binaryinsert(node *p, int key)
{
    if (p == nullptr)
    {
        node *t = new node;
        t->data = key;
        t->height = 1;
        t->lchild = t->rchild = nullptr;
        return t;
    }
    if (p->data > key)
        p->lchild = binaryinsert(p->lchild, key);
    else if (p->data < key)
        p->rchild = binaryinsert(p->rchild, key);
    p->height = height(p);
    if(balancefactor(p)==2&&balancefactor(p->lchild)==1)
    return LLroataion(p);
    else if(balancefactor(p)==2&&balancefactor(p->lchild)==-1)
    return LRroataion(p);
    else if(balancefactor(p)==-2&&balancefactor(p->rchild)==1)
    return RLroataion(p);
    else if(balancefactor(p)==-2&&balancefactor(p->rchild)==-1)
    return RRroataion(p);
    return p;
}
node* inprede(node*p)
{
    while(p&&p->rchild)
    {
        p=p->rchild;
    }
    return p;
}
node *insucc(node*p)
{
    while(p&&p->lchild)
    {
        p=p->lchild;
    }
    return p;
}


node* Delete(node *p,int key)
{   node*q;
    if(p==nullptr)
    return nullptr;
    if(p->lchild==nullptr&&p->rchild==nullptr)
    {
        if(root==p)
        root=nullptr;
        delete p;
        return nullptr;
    }
    if(p->data>key)
    p->lchild=Delete(p->lchild,key);
    else if(p->data<key)

    p->rchild=Delete(p->rchild,key);
    else 
    {
        if(height(p->lchild)>height(p->rchild))
        {  q=insucc(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);

                     
        }
        else
        {
            q=inprede(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        }
    }
    p->height=height(p);
    if(balancefactor(p)==2&&(balancefactor(p->lchild)==1||balancefactor(p->lchild)==0))
    return LLroataion(p);
    else if(balancefactor(p)==2&&balancefactor(p->lchild)==-1)
    return LRroataion(p);
     else if(balancefactor(p)==-2&&(balancefactor(p->lchild)==-1||balancefactor(p->rchild)==0))
    return RRroataion(p);
    else if(balancefactor(p)==-2&&balancefactor(p->lchild)==1)
    return RLroataion(p);
}

int main()
{

    root = binaryinsert(root, 30);
    binaryinsert(root, 10);
    binaryinsert(root, 40);
 
    binaryinsert(root, 20);
    binaryinsert(root, 5);
    // binaryinsert(root, 27);
    // binaryinsert(root, 5);
    Delete(root,40);
    inorder(root);
    cout<<endl;
    preorder(root);
}
