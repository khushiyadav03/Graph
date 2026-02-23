class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& image, int originalColor, int color, int m, int n){
        // boundary check
        if(row < 0 || row >= m || col < 0 || col >=n){
            return;
        }

        // check if curr cell == color
        if(image[row][col] != originalColor) return;

        // color the cell
        image[row][col] = color;

        // recurse in 4 directions
        dfs(row+1, col, image, originalColor, color, m, n);
        dfs(row-1, col, image, originalColor, color, m, n);
        dfs(row, col+1, image, originalColor, color, m, n);
        dfs(row, col-1, image, originalColor, color, m, n);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int originalColor = image[sr][sc];
        if(originalColor == color) return image;
        dfs(sr, sc, image, originalColor, color, m, n);
        return image;
    }
};