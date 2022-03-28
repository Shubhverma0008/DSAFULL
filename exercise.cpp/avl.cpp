#include<iostream>
#include<stack>
using namespace std;
struct node{
    node*lchild;
    int data;
    int height;
    node*rchild;
}*root=nullptr;

int height(node*p)
{
    if(p==nullptr)
    return 0;
    else
    {
        int x=p&&p->lchild?p->lchild->height:0;
        int y=p&&p->rchild?p->rchild->height:0;
        return x>y?x+1:y+1;
    }
}
node* LLrotation(node*p)
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
node* LRrotation(node*p)
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
    if(root==p)
    root=plr;
    return plr;

}
node* RLrotation(node*p)
{
    node*pr=p->rchild;
    node*prl=pr->lchild;
    node*prlr=prl->rchild;
    node*prll=prl->lchild;
    prl->rchild=pr;
    prl->lchild=p;
    p->rchild=prll;
    pr->lchild=prlr;
    p->height=height(p);
    prl->height=height(prl);
    pr->height=height(pr);
    if(root==p)
    root=prl;
    return prl;

}
node* RRrotation(node*p)
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

int bf(node*p)
{
    if(p==nullptr)
    return 0;
    else
    {
        int hl=p&&p->lchild?p->lchild->height:0;
        int hr=p&&p->rchild?p->rchild->height:0;
        return hl-hr;
    }
}
node* insucc(node*p)
{
    while(p&&p->lchild)
    {
        p=p->lchild;
    }
    return p;
}
node*inpre(node*p)
{
    while(p&&p->rchild)
    p=p->rchild;
    return p;
}
node*Delete(node*p,int key)
{
    if(p==nullptr)
    return nullptr;
    if(!p->lchild&&!p->rchild&&p->data==key)
    {
        if(root==p)
        root=nullptr;
        delete p;
        return nullptr;
    }
   
        if(key<p->data)
        p->lchild=Delete(p->lchild,key);
        else if(key>p->data)
        p->rchild=Delete(p->rchild,key);
        else
        {
            if(height(p->lchild)>height(p->rchild))
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
        p->height=height(p);
         p->height=height(p);
    if(bf(p)==2&&(bf(p->lchild)==1||bf(p->lchild)==0))
    return LLrotation(p);
    else if(bf(p)==2&&bf(p->lchild)==-1)
    return LRrotation(p);
     if(bf(p)==-2&&(bf(p->rchild)==-1||bf(p->rchild)==0))
    return RRrotation(p);
    else if(bf(p)==-2&&bf(p->rchild)==1)
    return RLrotation(p);

    return p;

   
}
node *createavl(node*p,int key)
{
    if(p==nullptr)
    {
        node*t=new node;
        t->data=key;
        t->height=1;
        t->lchild=t->rchild=nullptr;
        return t;
    }
    else {
        if(key<p->data)
        p->lchild=createavl(p->lchild,key);
        else if(key>p->data)
        p->rchild=createavl(p->rchild,key);
    }
    p->height=height(p);
    if(bf(p)==2&&bf(p->lchild)==1)
    return LLrotation(p);
    else if(bf(p)==2&&bf(p->lchild)==-1)
    return LRrotation(p);
    if(bf(p)==-2&&bf(p->rchild)==-1)
    return RRrotation(p);
    else if(bf(p)==-2&&bf(p->rchild)==1)
    return RLrotation(p);

    return p;


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
    stack<node*> st;
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
            cout<<" ("<<p->data<<" "<<p->height<<") ";
            p=p->rchild;
        }
    }
}
int main()
{
    root=createavl(root,30);
    // createavl(root,10);
    // createavl(root,40);
    // createavl(root,20);
    // createavl(root,5);
    // createavl(root,28);
    // createavl(root,27);
    // createavl(root,5);
    Delete(root,30);
    inorder(root);
    cout<<endl;
    preorder(root);
}