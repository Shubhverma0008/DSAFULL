#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
class list
{
public:
    node *first;

public:
    list()
    {
        first = nullptr;
    }
    list(int A[], int n);
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

    int linearsearch(int key);
};
int main()
{
     #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
     #endif
     int n;
     cin>>n;
     

}
