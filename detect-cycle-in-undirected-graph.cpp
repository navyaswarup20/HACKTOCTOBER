{
#include<bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cout << isCyclic(adj, V)<<endl;
    }
}

}
/*This is a function problem.You only need to complete the function given below*/
/* This function is used to detect a cycle in undirected graph
*  adj[]: array of vectors to represent graph
*  V: number of vertices
*/
bool isCyclicUtil(vector<int> adj[], int v, bool vis[], int p) {
    vis[v] = true;
    
    vector<int> :: iterator it;
    for(it = adj[v].begin(); it != adj[v].end(); it++) {
        if(!vis[*it]) {
            if(isCyclicUtil(adj, *it, vis, v))
                return true;
        }       
        else if(*it != p)
            return true;
    }
    
    return false;
}

bool isCyclic(vector<int> adj[], int V)
{
   // Your code here
    bool vis[V];
    memset(vis, false, sizeof(vis));
    
    for(int v = 0; v < V; v++)
        if(!vis[v])
            if(isCyclicUtil(adj, v, vis, -1))
                return true;
    
    return false;    
}