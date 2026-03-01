class Solution {
  public:
  
    bool dfs(int node, vector<vector<int>>& adj, 
             vector<int>& state, stack<int>& st) {
        
        state[node] = 1;  // mark as visiting
        
        for(int neighbor : adj[node]) {
            
            if(state[neighbor] == 0) {
                if(dfs(neighbor, adj, state, st))
                    return true;   // cycle found
            }
            else if(state[neighbor] == 1) {
                return true;       // back edge → cycle
            }
        }
        
        state[node] = 2;  // mark as fully visited
        st.push(node);    // push after exploring
        
        return false;
    }
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        
        vector<int> state(V, 0);
        stack<int> st;
        
        for(int i = 0; i < V; i++) {
            if(state[i] == 0) {
                if(dfs(i, adj, state, st))
                    return {};     // cycle detected
            }
        }
        
        vector<int> res;
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        
        return res;
    }
};