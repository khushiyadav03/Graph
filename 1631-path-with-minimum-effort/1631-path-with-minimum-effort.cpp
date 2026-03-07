class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        dist[0][0] = 0;

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        pq.push({0, 0, 0});

        vector<pair<int,int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int effort = get<0>(it);
            int r = get<1>(it);
            int c = get<2>(it);

            if(r == rows-1 && c == cols-1) return effort;

            for(auto d : dir){
                int nr = r + d.first;
                int nc = c + d.second;

                if(nr >= 0 && nr < rows && nc >= 0 && nc < cols){
                    int cost = abs(heights[r][c] - heights[nr][nc]);
                    int newEffort = max(effort, cost);

                    if(newEffort < dist[nr][nc]){
                        dist[nr][nc] = newEffort;
                        pq.push({newEffort, nr, nc});
                    }
                    if(effort > dist[r][c]) continue;
                }
            }
        }
        return 0;
    }
};