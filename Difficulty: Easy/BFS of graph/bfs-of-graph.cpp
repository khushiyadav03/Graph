class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<bool> visited(n, false);
        vector<int> res;
        queue<int>q;
        
        int start = 0;
        
        visited[start] = true;
        q.push(start);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(int n : adj[node]){
                if(!visited[n]){
                    visited[n] = true;
                    q.push(n);
                }
            }
        }
        return res;
    }
};