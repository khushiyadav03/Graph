class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        if(row < 0 || row >= m || col < 0 || col >= n) return;

        if(board[row][col] != 'O') return;

        board[row][col] = '#';

        dfs(row+1, col, board);
        dfs(row-1, col, board);
        dfs(row, col+1, board);
        dfs(row, col-1, board);
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        // first and last row
        for(int j = 0; j<n; j++){
            if(board[0][j] == 'O') dfs(0, j, board);
            if(board[m-1][j] == 'O') dfs(m-1, j, board);
        }

        // first and last col
        for(int i = 0; i<m; i++){
            if(board[i][0] == 'O') dfs(i, 0, board);
            if(board[i][n-1] == 'O') dfs(i, n-1, board);
        }

        // Flip remaining O to X, and # back to O
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};