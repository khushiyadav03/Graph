class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 2) 
                    q.push({i, j});
                else if (grid[i][j] == 1) 
                    fresh++;
            }
        }

        if(fresh == 0) return 0;
        int minutes = 0;
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        while(!q.empty() && fresh > 0){
            int size = q.size();
            for(int i = 0; i<size; i++){
                auto curr = q.front();
                q.pop();
                int x = curr.first;
                int y = curr.second;

                for(int d = 0; d<4; d++){
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1){
                        grid[nx][ny] = 2;
                        fresh--;
                        q.push({nx, ny});
                    }
                }
            }
            minutes++;
        }
        if(fresh > 0) return -1;
        return minutes;
    }
};