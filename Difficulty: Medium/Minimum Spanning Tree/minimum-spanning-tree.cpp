class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        vector<int> key(V, INT_MAX);
        vector<bool> visited(V,false);
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        key[0] = 0;
        pq.push({0,0});
        int sum = 0;
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            int wt = it.first;
            int node = it.second;
            
            if(visited[node]) continue;
            
            visited[node] = true;
            sum += wt;
            
            for(auto nbr : adj[node]){
                
                int adjNode = nbr.first;
                int edgeWt = nbr.second;
                
                if(!visited[adjNode]){
                    pq.push({edgeWt, adjNode});
                }
            }
        }
        
        return sum;
    }
};