class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        if(row >= m || row < 0 || col >= n || col < 0) return;

        if(grid[row][col] != 1) return;

        grid[row][col] = 0;

        dfs(row+1, col, grid);
        dfs(row-1, col, grid);
        dfs(row, col+1, grid);
        dfs(row, col-1, grid);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // first and last row
        for(int j = 0; j<n; j++){
            if(grid[0][j] == 1) dfs(0, j, grid);
            if(grid[m-1][j] == 1) dfs(m-1, j, grid);
        }

        // first and last col
        for(int i = 0; i<m; i++){
            if(grid[i][0] == 1) dfs(i, 0, grid);
            if(grid[i][n-1] == 1) dfs(i, n-1, grid);
        }

        int count = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1) count++;
            }
        }
        return count;
    }
};