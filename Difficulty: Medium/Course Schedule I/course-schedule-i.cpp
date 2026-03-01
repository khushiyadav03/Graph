class Solution {
  public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& state){
        if(state[node] == 1) return true;
        if(state[node] == 2) return false;
        state[node] = 1;
        for(int n : adj[node]){
            if(dfs(n, adj, state)) return true;
        }
        state[node] = 2;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& arr) {
        vector<vector<int>> adj(n);
        for(int i = 0; i<arr.size(); i++){
            int a = arr[i][0];
            int b = arr[i][1];
            adj[b].push_back(a);
        }
        vector<int> state(n, 0);
        for(int i = 0; i<n; i++){
            if(state[i] == 0){
                if(dfs(i, adj, state)) return false;
            }
        }
        return true;
    }
};