#include <iostream>
#include <queue>
#include<stack>

using namespace std;
 
void BFS(int vtx, int A[][8], int n){
    queue<int> q;
   vector<int>visited(8,0);
    cout<<vtx<<" ";
    visited[vtx]=1;
    q.push(vtx);
  while(!q.empty())
    {
        int u=q.front();   
        q.pop();
        for(int v=1;v<=n;v++)
        {
            if(A[u][v]==1&&visited[v]==0)
            {
                cout<<v<<" ";
                q.push(v);
                visited[v]=1;
            }
        }
    }
    cout<<endl;
 
}
void DFSstack(int A[][8],int vtx,int n)
{
    stack<int>st;
    st.push(vtx);
    int a[8]={0};
    while(!st.empty())
    {
       int  u=st.top();
        st.pop();
        if(a[u]!=1)
        {
            cout<<u<<" ";
            a[u]=1;
            for(int v=0;v<n;v++)
            {
                if(A[u][v]==1&&a[v]==0)
                st.push(v);
            }

        }

    }
}
void DFS(int A[][8],int vtx,int n)
{
    static vector<int>visi(8,0);
    if(visi[vtx]==0)
    {
        cout<<vtx<<" ";
        visi[vtx]=1;
        for(int v=1;v<=n;v++)

        {
            if(A[vtx][v]==1&&visi[v]==0)
            {
                DFS(A,v,n);
            }
        }
    }
}
 
int main (){
 
    int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 1, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 1, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};
 
    // cout << "Vertex: 1 -> " << flush;
    // DFSstack(A,5,8);
    // cout<<endl;
    // DFS( A,5, 8);
    // BFS(1, A, 8);
    // cout << "Vertex: 1 -> " << flush;
    // cout<<endl;
    cout<<endl;
 
    cout << "Vertex: 2 -> " << flush;
    DFS( A,6, 8);
 
 
    return 0;
}