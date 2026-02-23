class Solution {
  public:
    bool dfs(int node, int parent, vector<int>& visited, vector<vector<int>>& adj){
        visited[node] = 1;
        for(int n : adj[node]){
            if(!visited[n]){
                if(dfs(n, node, visited, adj)) return true;
            } else if (n != parent){
                return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        // adjacency list
        vector<vector<int>> adj(V);
        for(int i = 0; i<edges.size(); i++){
            int u = edges[i][0];
            int w = edges[i][1];
            adj[u].push_back(w);
            adj[w].push_back(u);
        }
        
        // visited array
        vector<int> visited(V, 0);
        
        // check all components
        for(int i = 0; i<V; i++){
            if(!visited[i]){
                if(dfs(i, -1, visited, adj)){
                    return true;
                }
            }
        }
        return false;
    }
};