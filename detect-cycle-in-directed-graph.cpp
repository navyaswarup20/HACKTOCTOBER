{
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}
}
/*This is a function problem.You only need to complete the function given below*/
/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/
bool isCyclicUtil(int v, vector<int> adj[], bool vis[], bool* res) {
    if(vis[v] == false){
        vis[v] = true;
        res[v] = true;
    
        vector<int> :: iterator it;
        for(it = adj[v].begin(); it != adj[v].end(); it++) {
            if(!vis[*it] && isCyclicUtil(*it, adj, vis, res))
                return true;
            else if(res[*it])
                return true;
        }
    }
    res[v] = false;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    // Your code here
    bool vis[V], rec[V];
    memset(vis, false, sizeof(vis));
    memset(rec, false, sizeof(rec));
    
    for(int v = 0; v < V; v++) {
        if(isCyclicUtil(v, adj, vis, rec))
            return true;
    }
    
    return false;
}