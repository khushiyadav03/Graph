class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        // Create adjacency list
        vector<vector<int>> adj(V);
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        
        // Compute indegree
        vector<int> indegree(V, 0);
        for(int u = 0; u < V; u++){
            for(int v : adj[u]) {
                indegree[v]++;
            }
        }
        
        // Push all nodes with indegree 0
        queue<int> q;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> res;
        
        // BFS
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            
            for(int n : adj[node]){
                indegree[n]--;
                if(indegree[n] == 0) {
                    q.push(n);
                }
            }
        }
        
        // Check for cycle
        if(res.size() != V) return {};
        
        return res;
    }
};