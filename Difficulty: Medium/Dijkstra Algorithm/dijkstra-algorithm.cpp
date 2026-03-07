class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>> adj(V);
        for(int i = 0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int d = it.first;
            int node = it.second;
                
            if(d > dist[node]) continue;
            
            for(auto &it : adj[node]){
                int adjNode = it.first;
                int wt = it.second;
                
                if(dist[node] + wt  < dist[adjNode]){
                    dist[adjNode] = dist[node] + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        
        return dist;
    }
};