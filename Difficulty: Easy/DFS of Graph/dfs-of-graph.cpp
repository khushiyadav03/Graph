class Solution {
public:
    vector<int> dfs(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<int> visited(n, 0);
        vector<int> result;
        stack<int> st;

        st.push(0);

        while (!st.empty()) {
            int curr = st.top();
            st.pop();

            if (visited[curr]) continue;

            visited[curr] = 1;
            result.push_back(curr);

            for (int i = adj[curr].size() - 1; i >= 0; i--) {
                int neighbor = adj[curr][i];
                if (!visited[neighbor]) {
                    st.push(neighbor);
                }
            }
        }

        return result;
    }
};