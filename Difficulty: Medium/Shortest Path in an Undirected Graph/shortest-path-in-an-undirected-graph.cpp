class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto &vec : edges){
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        vector<int> res(n+1, INT_MAX);
        vector<int> parent(n+1);
        for(int i = 0; i<=n; i++){
            parent[i] = i;
        }
        
        res[1] = 0;
        pq.push({0, 1});
        
        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto &it : adj[node]){
                int adjNode = it.first;
                int dist = it.second;
                if(d + dist < res[adjNode]){
                    res[adjNode] = d + dist;
                    pq.push({d + dist, adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        
        if(res[n] == INT_MAX) return {-1};
        
        vector<int> path;
        int node = n;
        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        path.insert(path.begin(), res[n]);
        
        return path;
    }
};