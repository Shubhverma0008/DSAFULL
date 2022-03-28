#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,int> PII;
void  primsSimple()
{
    int n=7;
    vector<vector<int>>edges{{0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}};
    vector<vector<int>>graph(n,vector<int>(n,INT_MAX));
    for(auto i:edges)
    {
        graph[i[0]][i[1]]=i[2];
        graph[i[1]][i[0]]=i[2];
    }
    vector<int>near(n,INT_MAX);
    vector<vector<int>>tree(2,vector<int>(n-1));
    int res=INT_MAX,u,v,k;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++){
            if(graph[i][j]<res){
                res=graph[i][j];
                u=i;
                v=j;
            }
        }
    }
    tree[0][0]=u;
    tree[1][0]=v;
    near[u]=near[v]=-1;
    int t;
    for(int i=0;i<n;i++){
        if(near[i]!=-1&&graph[u][i]<graph[v][i])
        near[i]=u;
        else if(near[i]!=-1)
        near[i]=v;
        t=near[i];
    }
   
    for(int i=1;i<n-1;i++){
        res=INT_MAX;
        for(int i=0;i<n;i++){
            if(near[i]!=-1&&graph[i][near[i]]<res){
                res=graph[i][near[i]];
                k=i;
            }
        }
        
        tree[0][i]=k;
        tree[1][i]=near[k];
        near[k]=-1;
        for(int i=0;i<n;i++){
            if(near[i]!=-1&&graph[i][k]<graph[i][near[i]])
            near[i]=k;
        }

    }
    int sum=0;
    for(int i=0;i<n-1;i++)
    {    sum+=graph[tree[0][i]][tree[1][i]];
        cout<<"Cost from [ "<<tree[0][i]<<" --> "<<tree[1][i]<<" ]  is = "<<graph[tree[0][i]][tree[1][i]]<<endl;
    }
    cout<<"total cost-=> "<<sum;
}
int primsHeap(){
     int n=7;
    vector<vector<int>>edges{{0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}};
    unordered_map<int,vector<pair<int,int>>>m;
    for(auto i:edges)
 {   m[i[0]].push_back({i[1],i[2]});
    m[i[1]].push_back({i[0],i[2]});}
    priority_queue<PII,vector<PII>,greater<PII>>Q;
    Q.push({0,2});//(cost,node)
    long long minCost=0;
    vector<bool>visited(n,false);
    while(!Q.empty()){
        auto p=Q.top();
        Q.pop();
        if(visited[p.second])continue;
        minCost+=p.first;
        visited[p.second]=true;
        for(auto curr:m[p.second]){
            if(visited[curr.first]==false){
                Q.push({curr.second,curr.first});
                //  tree.push_back({p.second,curr.first});
            }
        }
    }
    
    cout<<endl;
    cout<<minCost<<endl;
}
int main(){
     #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    primsSimple();
    cout<<endl;
    primsHeap();



}
