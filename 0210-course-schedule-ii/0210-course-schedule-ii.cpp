class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& state, vector<int>& order){
        // if currently visiting ->cycle
        if(state[node] == 1) return true;

        // already processed -> no cylce here
        if(state[node] == 2) return false;

        // mark visiting
        state[node] = 1;

        for(int n : adj[node]){
            if(dfs(n, adj, state, order)) return true;
        }

        state[node] = 2;
        order.push_back(node);

        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i = 0; i<prerequisites.size(); i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            adj[b].push_back(a);
        }
        vector<int> state(numCourses, 0);
        vector<int> order;
        for(int i = 0; i<numCourses; i++){
            if(state[i] == 0){
                if(dfs(i, adj, state, order)) return {};
            }
        }
        reverse(order.begin(), order.end());
        return order;
    }
};