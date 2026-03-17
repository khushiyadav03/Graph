class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited){
        visited[node] = 1;
        for(int n : adj[node]){
            if(!visited[n]) dfs(n, adj, visited);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;

        vector<vector<int>> adj(n);
        for(int i =0; i<connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int components = 0;
        vector<int> visited(n, 0);
        for(int i = 0; i<n; i++){
            if(!visited[i]){
                components++;
                dfs(i, adj, visited);
            }
        }
        return components - 1;
    }
};