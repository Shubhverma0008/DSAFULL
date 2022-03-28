#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
class linkedlist
{
public:
    node *first;

public:
    linkedlist() { first = nullptr; }
    linkedlist(int A[], int n);
    void display();
    void rdisplay(node *p);
    int countnode();
    int rcountnode(node *p);
    int rcountnode() { rcountnode(first); }
    int sum(node *p);
    int sum() { sum(first); }
    int max(node *p);
    int max() { max(first); }
    void insert(int pos, int x);
    void sortedinsert(int x);
    void Delete(int pos);
    bool sort();
    void duplicate();
    void reverselist();
    void rrverse(node *q, node *p);

    int linearsearch(int key)
    {
        node *p = first;
        while (p)
        {
            if (p->data == key)
                return key;
            p = p->next;
        }
        return -1;
    }
};
void linkedlist::rrverse(node *q, node *p)
{
    if (p)
    {
        rrverse(p, p->next);
        p->next = q;
    }
    else
        first = q;
}
void linkedlist::insert(int pos, int x)
{
    node *p = first, *t;
    if (pos == 0)
    {
        t = new node;
        t->data = x;
        t->next = first;
        first = t;
    }
    else
    {
        if (pos > 0)

        {
            for (int i = 0; i < pos - 1; i++)
                p = p->next;
        }
    }
    if (p)
    {
        t = new node;
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}
void linkedlist::sortedinsert(int x)
{
    node *p = first;
    node *q = nullptr;

    while (p && p->data < x)
    {
        q = p;
        p = p->next;
    }
    node *t = new node;
    t->data = x;
    t->next = nullptr;
    if (p == first)
    {
        t->next = first;
        first = t;
    }
    else
    {
        t->next = q->next;
        q->next = t;
    }
}
int linkedlist::countnode()
{
    node *p = first;
    int count = 0;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}
int linkedlist::rcountnode(node *p)
{
    if (p)
    {
        return rcountnode(p->next) + 1;
    }
    else
        return 0;
}
int linkedlist::sum(node *p)
{
    if (p == nullptr)
        return 0;
    else
    {
        return sum(p->next) + p->data;
    }
}
linkedlist::linkedlist(int A[], int n)

{
    node *last, *temp;
    first = new node;
    first->data = A[0];
    first->next = nullptr;
    last = first;
    for (int i = 1; i < n; i++)
    {
        temp = new node;
        temp->data = A[i];
        temp->next = nullptr;
        last->next = temp;
        last = temp;
    }
}
void linkedlist::display()
{
    node *p = first;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
void linkedlist::rdisplay(node *p)
{
    if (p)
    {
        rdisplay(p->next);
        cout << p->data << " ";
    }
    else
        return;
}
int linkedlist::max(node *p)
{
    if (p == nullptr)
        return INT32_MIN;
    else
    {
        int x = max(p->next);
        return x > p->data ? x : p->data;
    }
}
void linkedlist::Delete(int pos)
{
    node *p = first;
    node *q;
    if (pos == 0)
    {
        first = first->next;
        delete p;
    }
    else
    {
        for (int i = 0; i < pos && p; i++)
        {
            q = p;
            p = p->next;
        }
        if (p)
        {
            q->next = p->next;
            delete p;
        }
    }
}
bool linkedlist::sort()
{
    node *p = first;
    while (p && p->next)
    {
        if (p->data > p->next->data)
            return false;
        p = p->next;
    }
    return true;
}
void linkedlist::duplicate()
{
    node *p = first;
    node *q = first->next;
    while (q)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}
void linkedlist::reverselist()
{
    node *p = first;
    node *q, *r;
    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

int main()
{
    int A[] = {10, 20, 30, 40, 50, 60, 70};
    linkedlist l(A, 7);
    // cout<<l.sort();
    l.rrverse(nullptr, l.first);

    // cout<<l.sum();
    // cout<<l.max()<<endl;
    // cout<<l.countnode()<<endl;
    // cout<<l.rcountnode();
    // l.insert(8,10);
    //    l.Delete(5);
    // l.duplicate();
    // l.reverselist();

    cout << endl;
    l.display();
}
