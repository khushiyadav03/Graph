class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> outdegree(n);
        vector<vector<int>> reverseGraph(n);
        queue<int> q;

        // build reverse graph and outdegree
        for(int i = 0; i < n; i++){
            for(int x : graph[i]){
                outdegree[i]++;
                reverseGraph[x].push_back(i);
            }
        }

        // push terminal nodes (outdegree 0)
        for(int i = 0; i < n; i++){
            if(outdegree[i] == 0)
                q.push(i);
        }

        vector<int> safe;

        // kahn's algorithm
        while(!q.empty()){
            int node = q.front();
            q.pop();

            safe.push_back(node);

            for(int p : reverseGraph[node]){
                outdegree[p]--;
                if(outdegree[p] == 0)
                    q.push(p);
            }
        }

        sort(safe.begin(), safe.end());
        return safe;
    }
};