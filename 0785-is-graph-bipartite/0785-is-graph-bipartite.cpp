class Solution {
public:
    bool dfs(int node, int currColor, vector<vector<int>>& graph, vector<int>& color) {
        color[node] = currColor;
        for(int n : graph[node]){
            if(color[n] == -1){
                if(!dfs(n, 1- currColor, graph, color)) return false;
            } else if(color[n] == currColor) return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i = 0; i<n; i++){
            if(color[i] == -1){
                if(!dfs(i, 0, graph, color)) return false;
            }
        }
        return true;
    }
};