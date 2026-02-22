// User function Template for C++

class Solution {
  public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& visited, int n){
        visited[node] = true;
        for(int i = 0; i<n; i++){
            if(isConnected[node][i] == 1 && !visited[i]){
                dfs(i, isConnected, visited, n);
            }
        }
    }
    
    int numProvinces(vector<vector<int>> isConnected, int V) {
        int n = isConnected.size();
        int count = 0;
        vector<bool> visited(n, false);

        for(int i = 0; i<n; i++){
            if(!visited[i]){
                count++;
                dfs(i, isConnected, visited, n);
            }
        }

        return count;
    }
};