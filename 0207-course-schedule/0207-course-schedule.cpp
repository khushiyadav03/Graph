class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& state){
        // if currently visiting ->cycle
        if(state[node] == 1) return true;

        // already processed -> no cylce here
        if(state[node] == 2) return false;

        // mark visiting
        state[node] = 1;

        for(int n : adj[node]){
            if(dfs(n, adj, state)) return true;
        }

        state[node] = 2;

        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i = 0; i<prerequisites.size(); i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            adj[b].push_back(a);
        }

        vector<int> state(numCourses, 0);
        for(int i = 0; i<numCourses; i++){
            if(state[i] == 0){
                if(dfs(i, adj, state)) return false;
            }
        }
        return true;
    }
};