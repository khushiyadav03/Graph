class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0; i < flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];

            adj[u].push_back({v, w});
        }

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        pq.push({0, src, 0});

        vector<vector<int>> dist(n, vector<int>(k+2, INT_MAX));
        dist[src][0] = 0;

        while(!pq.empty()){

            auto it = pq.top();
            pq.pop();

            int cost = get<0>(it);
            int node = get<1>(it);
            int stops = get<2>(it);

            if(node == dst) return cost;

            if(stops == k + 1) continue;

            for(auto d : adj[node]){

                int newNode = d.first;
                int price = d.second;

                int newCost = cost + price;

                if(newCost < dist[newNode][stops+1]){
                    dist[newNode][stops+1] = newCost;
                    pq.push({newCost, newNode, stops+1});
                }
            }
        }

        return -1;
    }
};