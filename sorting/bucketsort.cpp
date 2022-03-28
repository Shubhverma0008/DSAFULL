#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
int findmax(int A[], int n)
{
    int x = A[0];
    for (int i = 1; i < n; i++)
    {
        if (A[i] > x)
            x = A[i];
    }
    return x;
}
void insert(node **bin, int x)
{
    node *temp = new node;
    temp->data = x;
    temp->next = nullptr;
    if (bin[x] == nullptr)
        bin[x] = temp;
    else
    {
        node *p = bin[x];
        while (p->next)
            p = p->next;
        p->next = temp;
    }
}
int Delete(node **bin, int x)

{
    int k;

    node *p = bin[x];
    bin[x] = bin[x]->next;
    k = p->data;
    delete p;
    return k;
}
void bucketsort(int A[], int n)
{
    node **bin;
    int max=findmax(A,n);
    bin = new node *[max + 1];
    for (int i = 0; i < max + 1; i++)
    {
        bin[i] = nullptr;
    }
    for (int i = 0; i < n; i++)
    {
        insert(bin, A[i]);
    }
    int i = 0, j = 0;
    while (i < max + 1)
    {
        while (bin[i] != nullptr)
        {
            A[j++] = Delete(bin, i);
        }
        i++;
    }
    delete []bin;
}

int main()
{
    int A[] = {6, 8, 3, 10, 15, 6, 9, 12, 6, 3};
    bucketsort(A, 10);
    for (auto i : A)
        cout << i << " ";
}