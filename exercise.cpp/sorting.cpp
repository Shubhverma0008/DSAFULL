#include <iostream>
#include <queue>
#include <stack>
#include<algorithm>
#define V 8
#define I INT32_MAX
using namespace std;
void bubblesort(int A[], int n)
{
    int flag = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (A[j + 1] < A[j])
            {
                swap(A[j + 1], A[j]);
               
            }
        }
    }
    if (flag == 1)
        cout << "not sorted ";
    if (flag == 0)
        cout << "sorted";
}
// void insertionsort(int A[], int n)
// {
//     int flag = 1;
//     for (int i = 1; i < n; i++)
//     {
//         int temp = A[i];
//         int j = i - 1;
//         while (A[j] > temp && j >= 0)
//         {
//             A[j + 1] = A[j];
//             j--;
//             flag = 0;
//         }
//         A[j + 1] = temp;
//     }
//     if (flag == 1)
//         cout << "array is sorted";
//     else
//         cout << "not";
// }
// void seleection(int A[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         int k = i;
//         for (int j = i; j < n; j++)
//         {
//             if (A[j] < A[k])
//                 k = j;
//         }
//         swap(A[i], A[k]);
//     }
// }
// int findmax(int A[], int n)
// {
//     int max = INT8_MIN;
//     for (int i = 0; i < n; i++)
//     {
//         if (max < A[i])
//             max = A[i];
//     }
//     return max;
// }
// void count(int A[], int n)
// {
//     int max = findmax(A, n);
//     int *c;
//     c = new int[max + 1];
//     for (int i = 0; i < max + 1; i++)
//         c[i] = 0;
//     for (int i = 0; i < n; i++)
//         c[A[i]]++;
//     int i, j = 0;
//     i = 0;
//     while (i < max + 1)
//     {
//         if (c[i] > 0)
//         {
//             A[j++] = i;
//             c[i]--;
//         }
//         else
//             i++;
//     }
// }
// void BFS(int G[V][V], int vtx, int n)
// {
//     int visited[V] = {0};
//     queue<int> q;
//     if (visited[vtx] == 0)
//         cout << vtx << " ";
//     visited[vtx] = 1;
//     q.push(vtx);
//     while (!q.empty())
//     {
//         int u = q.front();
//         q.pop();

//         for (int v = 0; v <= n; v++)
//         {
//             if (G[u][v] == 1 && visited[v] == 0)
//             {
//                 cout << v << " ";
//                 q.push(v);
//                 visited[v] = 1;
//             }
//         }
//         // cout<<endl;
//     }
// }
// void DFS(int G[V][V], int vtx, int n)
// {
//     static int visi[V] = {0};
//     if (visi[vtx] == 0)
//     {
//         cout << vtx << " ";
//         visi[vtx] = 1;
//         for (int v = 1; v <= n; v++)
//         {
//             if (G[vtx][v] == 1)
//             {
//                 if (visi[v] == 0)
//                     DFS(G, v, n);
//             }
//         }
//     }
// }
// void DFSstack(int G[V][V], int vtx, int n)
// {
//     static int visi[V] = {0};
//     stack<int> st;
//     st.push(vtx);
//     while (!st.empty())
//     {
//         int u = st.top();
//         st.pop();
//         if (visi[u] == 0)
//         {
//             cout << u << " ";
//             visi[u] = 1;

//             for (int v = 1; v <= n; v++)
//                 if (G[u][v] == 1 && visi[v] == 0)
//                 {
//                     st.push(v);
//                 }
//         }
//     }
// }
// void print(int T[2][V - 2], int G[V][V])
// {  cout<<"spanning tree->";
// int sum=0;

//     for (int i = 0; i < V - 2; i++)
//     {
//         int c=G[T[0][i]][T[1][i]];
//         sum+=c;
//         cout << T[0][i] << "->" << T[1][i] <<" cost  " <<c<< endl;
//     }
//     cout<<"total cast is "<<sum;
// }
// void printmst(int T[][V-2], int G[V][V]){
//     cout << "\nMinimum Spanning Tree Edges (w/ cost)\n" << endl;
//     int sum {0};
//     for (int i {0}; i<V-2; i++){
//         int c = G[T[0][i]][T[1][i]];
//         cout << "[" << T[0][i] << "]---[" << T[1][i] << "] cost: " << c << endl;
//         sum += c;
//     }
//     cout << endl;
//     cout << "Total cost of MST: " << sum << endl;
// }
// void Prime(int G[V][V], int n)
// {
//     int u, v;
//     int min = I;
//     int near[V]  {I};
//     int track[2][V - 2] ;
//     for (int i = 1; i <= n; i++)
//      {  near[i]=I;
//         for (int j = 1; j <= n; j++)
//         {
//             if (G[i][j] < min)
//             {
//                 min = G[i][j];
//                 u = i;
//                 v = j;
//             }
//         }
//     }
//     near[u] = 0;
//     near[v] = 0;
//     track[0][0] = u;
//     track[1][0] = v;
//     for (int i = 1; i < V; i++)
//     {
//         if (near[i] != 0)
//         {
//             if (G[i][u] < G[i][v])
//                 near[i] = u;
//             else
//                 near[i] = v;
//         }
//     }
//     for (int i = 1; i < n - 1; i++)
//     {
//         min = I;
//         int k;
//         for (int j = 1; j < V; j++)
//         {
//             if (near[j] != 0 && G[j][near[j]] < min)
//             {
//                 min = G[j][near[j]];
//                 k = j;
//             }
//         }
//         track[0][i] = k;
//         track[1][i] = near[k];
//         near[k] = 0;
//         for (int j = 1; j < V; j++)
//         {

//                 if (near[j]!=0&&G[j][k] < G[j][near[j]])
//                     near[j] = k;

//         }
//     }
//     printmst(track, G);
// }
// void merge(int A[], int l, int mid, int h)
// {
//     int i = l;
//     int j = mid + 1;
//     int k = l;
//     int B[100];
//     while (i <= mid && j <= h)
//     {
//         if (A[i] < A[j])
//             B[k++] = A[i++];
//         else
//             B[k++] = A[j++];
//     }
//     for (; i <= mid; i++)
//         B[k++] = A[i];
//     for (; j <= h; j++)
//         B[k++] = A[j];
//     for (int i = 0; i <= h; i++)
//     {
//         A[i] = B[i];
//     }
// }
// void iterativemerger(int A[], int n)
// {
//     int p;
//     for (p = 2; p <= n; p = p * 2)
//     {
//         for (int i = 0; i + p - 1 < n; i = i + p)
//         {
//             int l = i;
//             int h = i + p - 1;
//             int mid = (l + h) / 2;
//             merge(A, l, mid, h);
//         }
//     }
//     if (p / 2 < n)
//     {
//         merge(A, 0, p / 2 - 1, n - 1);
//     }
// }
// void recursivemerge(int A[], int l, int h)
// {
//     if (l < h)
//     {
//         int mid = (l + h) / 2;
//         recursivemerge(A, l, mid);
//         recursivemerge(A, mid + 1, h);
//         merge(A, l, mid, h);
//     }
// }
// void shell(int A[], int n)
// {
//     for (int gap = n / 2; gap >= 1; gap /= 2)
//     {
//         for (int j = gap; j < n; j++)
//         {
//             int i = j - gap;
//             int temp = A[j];
//             while (i >= 0 && temp < A[i])
//             {
//                 A[i + gap] = A[i];
//                 i = i - gap;
//             }
//             A[i + gap] = temp;
//         }
//     }
// }
struct node
{
    int data;
    node*next;
};
void insert( node**bins,int x)
{
    node*temp=new node;
    temp->data=x;
    temp->next=nullptr;
    if(!bins[x])
    bins[x]=temp;
    else
    {
        node*p=bins[x];
        while(p->next)
        p=p->next;
        p->next=temp;
    }


}
int Delete(node**bins,int x)
{
    node*p=bins[x];
    bins[x]=bins[x]->next;
    int k=p->data;
    delete p;
    return k;

}

void bin(int A[],int n) 
{
    int max=15;
    node**bins;
    bins=new node*[max+1];
    for(int i=0;i<max+1;i++)
    {
        bins[i]=nullptr;
    }
    for(int i=0;i<n;i++)
    {
        insert(bins,A[i]);

    }
    int i=0;
    int j=0;
    while(i<max+1)
    {
        if(bins[i])
        {
            A[j++]=Delete(bins,i);

        }
        else i++;
    }



} 
string greatereven(string S,int n)
{
    sort(S.begin(),S.end(),greater<char> ());
     

        if((S[n]&1)==0)
        {
        return S ;}
        else
        {
            for(int i=n;i>=0;i--)
            {
                if((S[i]&1)==0)
                {
                    swap(S[i],S[n]);
                      {
                           break;}
                }
            }
            sort(S.begin(),S.begin()+n,greater<char>());
            return S;
            
        }
        return S;
       

}



  
 
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // int n;
    // cin >> n;
    // int A[n];
    // for (int i = 0; i < n; i++)
    //     cin >> A[i];
    // iterativemerger(A,9);
    // recursivemerge(A,0,7);
    // shell(A, n);
    // bin(A,n);
    string A;
    cin>>A;
    int n=A.length()-1;
    string k=greatereven(A,n);
    cout<<k;
    // cout<<A.length();
   
   
    // cout<<(A[2]&1);

    // for (auto i : A)
    //     cout << i << " ";
}