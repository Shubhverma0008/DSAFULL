#include<bits/stdc++.h>
using namespace std;
void KAHN(){
     int E,V;
    cin>>E>>V;
    unordered_map<int,vector<int>>m;
    vector<int>indegree(V,0);
    for(int i=0;i<E;i++){
        int x,y;
        cin>>x>>y;
        m[x].push_back(y);
        indegree[y]++;
    }
    queue<int>Q;
    for(int i=0;i<V;i++){
        if(indegree[i]==0)Q.push(i);
    }
    vector<int>ans;
    int count=0;
    while(!Q.empty()){
        int p=Q.front();
        Q.pop();
        for(auto curr:m[p]){
            if(--indegree[curr]==0)
            Q.push(curr);

        }
        ans.push_back(p);
        count++;

    }
    for(auto i:ans)cout<<i<<" ";
    cout<<endl;
    cout<<count<<endl;

}
bool DFS(int vtx,int parent,vector<vector<int>>&adj ,vector<int>&visited){
    visited[vtx]=1;
    for(auto curr:adj[vtx]){
        if(visited[curr]==0&&DFS(curr,vtx,adj,visited))return true;
        else if(curr!=parent)return true;
    }
    return false;
}
bool cycleundirectDFS(){
    int V=8;
    vector<int>visited(V,0);
    vector<vector<int>> adj(V,vector<int>(V,0));
    for(int i=0;i<V;i++)
    {
        if(DFS(i,-1,adj,visited))return true;
    }
    return false;
}
bool cycleundirectBFS(){
    int V;
    vector<vector<int>>graph(V,vector<int>(V,0));//this should be adjacent list
    vector<int>visited(V,0);
    for(int i=0;i<V;i++){
        if(visited[i]==0){
            queue<pair<int,int>>q;
            q.push({i,-1});
            while(!q.empty()){
                auto p=q.front();
                q.pop();
                visited[p.first]=1;
                for(auto curr:graph[p.first]){
                    if(visited[curr]==0)
                    q.push({curr,p.first});
                    else if(curr!=p.second)return true;
                }
            }
        }
    }
    return false;

}
void DFS1(int vtx,vector<int>&visited,unordered_map<int,vector<int>>&m,vector<int>&st){
    visited[vtx]=1;
    for(auto curr:m[vtx])
    if(visited[curr]==0)
    DFS1(curr,visited,m,st);
    st.push_back(vtx);
}
 void DFS2(int vtx,vector<int>&visited,unordered_map<int,vector<int>>&m){
    visited[vtx]=1;
    cout<<vtx<<" ";
    for(auto curr:m[vtx])
    if(visited[curr]==0)
    DFS2(curr,visited,m);
}
void kosarajuforSCC()
{
    int E,V;
    cin>>V>>E;
    unordered_map<int,vector<int>>m;
    for(int i=0;i<E;i++)
    {
        int x,y;
        cin>>x>>y;
        m[x].push_back(y);
    }
    vector<int>visited(V,0);
    vector<int>st;

    for(int i=0;i<V;i++)
    if(visited[i]==0)
    DFS1(i,visited,m,st);


    unordered_map<int,vector<int>>rev;

    for(int i=0;i<V;i++)
    for(auto curr:m[i])
     rev[curr].push_back(i);

     for(int i=0;i<V;i++)
     visited[i]=0;


    cout<<endl<<" SCC are-> "<<endl;
     while (!st.empty())
     {
         int vtx=st.back();
         st.pop_back();
         if(visited[vtx]==0)
        { DFS2(vtx,visited,rev);
         cout<<endl;}
         
         

         
     }
     
    
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
     freopen("output.txt","w",stdout);
    #endif
    // KAHN();  //use for check cycle and topological
    // kosarajuforSCC(); //for strongly connected components


}