class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1,1}, {-1, -1}, {1, -1}, {-1, 1}};
        int r = board.size();
        int c = board[0].size();

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j <board[0].size(); j++){
                int liveNeighbours = 0;
                for(auto &it : dir){
                    int nr = i + it[0];
                    int nc = j + it[1];

                    if(nr >= 0 && nr < r && nc >= 0 && nc < c){
                        if(board[nr][nc] == 1 || board[nr][nc] == -1){
                            liveNeighbours++;
                        }
                    }
                }

                if(board[i][j] == 1){
                    if(liveNeighbours< 2 || liveNeighbours > 3){
                        board[i][j] = -1;
                    }
                } else {
                    if(liveNeighbours == 3){
                        board[i][j] = 2;
                    }
                }
            }
        }

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(board[i][j] > 0) board[i][j] = 1;
                else board[i][j] = 0;
            }
        }
    }
};