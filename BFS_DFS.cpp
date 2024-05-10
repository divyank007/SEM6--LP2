#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Graph
{
    int V;
    vector<vector<int>>adj;
    vector<int>visited;
    public:
    Graph(int n)
    {
        V=n;
        adj.resize(n);
        visited.resize(n,0);
    }
    void addEdge(int u,int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void dfs(int a,int l)
    {
        cout<<l;
        cout<<a<<endl;
        visited[a]=1;
        for(auto i:adj[a])
        {
            if(visited[i]==0)
            {
                dfs(i,l+1);
            }
        }
   
    }
    void bfs(int a)
    {
        queue<pair<int,int>>q;
        int level=0;

        q.push({a,level++});
        visited[a]=1;
        while(!q.empty())
        {

            int t=q.front().first;
            int level=q.front().second;
            q.pop();
            cout<<t<<" "<<level<<endl;
            for(auto i:adj[t])
            {
                if(visited[i]==0) q.push({i,level+1}),visited[i]=1;
            }
            
        }
        cout<<endl;
        for(int i=0;i<V;i++) visited[i]=0;
    }
};
int main()
{
    int t;
    cout<<"no. of vertices";
    cin>>t;
    Graph g(t);
    g.addEdge(0, 1);
    g.addEdge(0, 6);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.bfs(0);
    // g.dfs(0,0);
    

    return 0;
}