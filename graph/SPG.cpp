#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,int> PII;
int minValue(vector<int> &value, vector<int> &visited)
{
    int index, temp = INT_MAX;
    for (int i = 0; i < value.size(); i++)
        if (!visited[i] && value[i] < temp)
        {
            temp = value[i];
            index = i;
        }
    return index;
}
void DijsktraSimple(){
     int n = 7;
    vector<vector<int>> edges{{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};
    unordered_map<int, vector<pair<int, int>>> m;
    for (auto i : edges)
    {
        m[i[0]].push_back({i[1], i[2]});
        m[i[1]].push_back({i[0],i[2]});
    }
    vector<int> value(n, INT_MAX);
    vector<int> parent(n, -1);
    value[4] = 0;
    int t;
   
    vector<int> visited(n, 0);
    for (int i = 0; i < n - 1; i++)                //O(V)
    {
        int u = minValue(value, visited);       //O(V)
        if (u > n)
            break;
        visited[u] = 1;
        for (auto curr : m[u])           
        {
            if (visited[curr.first] == 0)
            {
                if (value[u] != INT_MAX && (value[u] + curr.second) < value[curr.first])
                    t = value[curr.first] = value[u] + curr.second;
                parent[curr.first] = u;
            }
        }
    }
    for (auto i : value)
        cout << i << "  ";
    cout << endl;
    for (auto i : parent)
        cout << i << "  ";               //timecomplexcity is O(n^2)



}
void DijsktraHeap(){
    
    int n = 7;
    vector<vector<int>> edges{{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};
    unordered_map<int, vector<pair<int, int>>> m;
    for (auto i : edges)
    {
        m[i[0]].push_back({i[1], i[2]});
        m[i[1]].push_back({i[0],i[2]});
    }
    vector<int> value(n, INT_MAX);
    vector<int> parent(n, -1);
    int src=4;
    value[src]=0;
    priority_queue<PII,vector<PII>,greater<PII>>Q;
    Q.push({0,src});//(cost,node)
    vector<int>visited(n,0);
    while(!Q.empty()){
        auto p=Q.top();
        Q.pop();
        if(visited[p.second])continue;
        visited[p.second]=1;
        for(auto curr:m[p.second]){
            int d=p.first+curr.second;
            if(visited[curr.first]==0&&d<value[curr.first]){
                value[curr.first]=d;
                parent[curr.first]=p.second;
                Q.push({d,curr.first});
            }
        }


    }
  
    for (auto i : value)
        cout << i << "  ";
    cout << endl;
    for (auto i : parent)
        cout << i << "  ";
        vector<int>res;
        for(int dst=1;dst!=-1;dst=parent[dst])
        res.push_back(dst);
        reverse(res.begin(),res.end());
        cout<<endl;
        for(auto i:res)cout<<i<<" ";
}
#define V 6
#define INF INT_MAX
struct edge{
    int src,dst,cost;
};
void bellmanford(){ 
    int E,v;
    cin>>E>>v;
    int src=0,dst=3;
    vector<edge>e(E);
    for(int i=0;i<E;i++){
        int x,y,z;
        cin>>x>>y>>z;
        e[i].src=x;
        e[i].dst=y;
        
        e[i].cost=z;
    }

    vector<int>value(v,INF);
    vector<int>path(v,-1);
    value[src]=0;
    for(int i=0;i<v-1;i++){
        bool any=true;
        for(int j=0;j<E;j++){
            if(value[e[j].src]!=INF&&(e[j].cost+value[e[j].src])<value[e[j].dst])
            {
                value[e[j].dst]=e[j].cost+value[e[j].src];
                path[e[j].dst]=e[j].src;
                any=false;
            }

               
        }
        if(any)break;
          for(auto i:path)cout<<i<<" ";
          cout<<endl;
    }
    cout<<endl;

    
vector<int>original;
for(int curr=dst;curr!=-1;curr=path[curr]){
    original.push_back(curr);
}
reverse(original.begin(),original.end());
for(auto i:original)cout<<i<<" ";
cout<<"path from "<<src<<" to "<< dst<<"  is-> \n ";
       for(int i=0;i<original.size();i++)
       {
           cout<<"Reach "<<original[i]<<" at  with cost of "<<value[original[i]]<<endl;

       }

  
    
    


}
void flyodWarshall(){
    int n = 7;
    vector<vector<int>> edges{{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};
    vector<vector<int>>graph(n,vector<int>(n,INT_MAX));
    for(int i=0;i<edges.size();i++){
        graph[edges[i][0]][edges[i][1]]=edges[i][2];
        graph[edges[i][1]][edges[i][0]]=edges[i][2];
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(graph[i][k]==INT_MAX||graph[k][j]==INT_MAX||i==j)continue;
                graph[i][j]=min(graph[i][k]+graph[k][j],graph[i][j]);
            }
        }
    }
    for(int i=0;i<V;i++)
     {
         if(graph[i][i]<0)
         cout<<"There is a negative edge wt cycle";
     }
    for(auto i:graph)
    {
        for(auto x:i)
        if(x==INT_MAX)
        cout<<" - ";
        else cout<<x<<" ";
        cout<<endl;
    }

}
int main(){
     #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    flyodWarshall();
    
    
   
  


}