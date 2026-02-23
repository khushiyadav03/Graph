class Solution {
  public:
    void dfs(int row, int col, vector<vector<int>>& image, int originalColor, int color, int m, int n){
        if(row < 0 || row >= m || col < 0 || col >= n) return;
        
        if(image[row][col] != originalColor) return;
        
        image[row][col] = color;
        
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