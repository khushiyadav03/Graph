class Solution {
public:
    vector<vector<int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int n;

    bool possibleToReach(vector<vector<int>>& grid, int i, int j, int t, vector<vector<bool>>& visited){
        if(i < 0 || i >= n || j <0 || j >= n || visited[i][j] == true || grid[i][j] > t){
            return false;
        }

        visited[i][j] = true;

        if(i == n-1 && j == n-1) return true;

        for(auto &d : dir){
            int nr = i + d[0];
            int nc = j + d[1];

            if(possibleToReach(grid, nr, nc, t, visited)){
                return true;
            }
        }

        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        int l = grid[0][0], r = n*n - 1;

        int result = 0, mid = 0;

        while(l <= r){
            mid = l +(r-l) / 2;
            vector<vector<bool>> visited(n, vector<bool>(n, false));
            if(possibleToReach(grid, 0, 0, mid, visited)){
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }
};