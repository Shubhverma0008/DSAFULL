#include <iostream>
using namespace std;
void insert(int A[], int n)
{
    int temp = A[n];
    int i = n;
    while (i > 1 && temp > A[i / 2])
    {
        A[i] = A[i / 2];
        i = i / 2;
    }
    A[i] = temp;
}
 void create(int A[], int n)
{
    for (int i = 2; i <= n; i++)
    {
        insert(A, i);
    }
}
void heapify(int A[], int n)
{

    int i;
    for (int k = n / 2; k >= 1; k--)
    {

        i = k;
        int j = 2 * i;
        while (j <= n - 1)
        {
            if (A[j + 1] > A[j])
                j = j + 1;
            if (A[i] < A[j])
            {
                swap(A[i], A[j]);
                i = j;
                j = 2 * i;
            }
            else
                break;
        }
    }
}
void Delete(int A[], int n)
{
    int x = A[1];
    A[1] = A[n];
    int i = 1;
    int j = 2 * i;
    while (j < n - 1)
    {
        if (A[j + 1] > A[j])
            j = j + 1;
        if (A[i] < A[j])
        {
            swap(A[i], A[j]);
            i = j;
            j = 2 * i;
        }
        else
            break;
    }
    A[n] = x;
}
int main()
{
    int H[] = {0,20,120,32,39,24,25,53,14,12,466,21};
    //    create(H,7);
    heapify(H, 11);

       Delete(H,11);
       Delete(H,10);
       Delete(H,9);
       Delete(H,8);
       Delete(H,7);
       Delete(H,6);
       Delete(H,5);
       Delete(H,4);
       Delete(H,3);
       Delete(H,2);
    for (int i = 1; i <= 11; i++)
    {
        cout << H[i] << " ";
    }
    return 0;
}