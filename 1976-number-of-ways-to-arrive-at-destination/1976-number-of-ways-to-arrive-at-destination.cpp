class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        long long mod = 1e9 + 7;
        for(int i = 0; i<roads.size(); i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        dist[0] = 0, ways[0] = 1;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            long long time = it.first;
            int node = it.second;

            for(auto d : adj[node]){
                int adjNode = d.first;
                int wt = d.second;
                long long newtime = time + wt;

                if(newtime < dist[adjNode]){
                    dist[adjNode] = newtime;
                    ways[adjNode] = ways[node];
                    pq.push({newtime, adjNode});
                } else if(newtime == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};