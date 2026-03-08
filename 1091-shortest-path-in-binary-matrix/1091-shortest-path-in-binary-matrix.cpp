class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;

        queue<tuple<int, int, int>> q;
        q.push({0, 0, 1});
        grid[0][0] = 1;

        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1},{1, -1}, {-1, 1}, {-1, -1}};

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int r = get<0>(it);
            int c = get<1>(it);
            int dist = get<2>(it);

            if(r == n-1 && c == m-1) return dist;

            for(auto d : dir){
                int nr = r + d.first;
                int nc = c + d.second;

                if((nr >= 0 && nr < n && nc >= 0 && nc < m) && (grid[nr][nc] == 0)){
                    grid[nr][nc] = 1;
                    q.push({nr, nc, dist + 1});
                }
            }
        }
        return -1;
    }
};