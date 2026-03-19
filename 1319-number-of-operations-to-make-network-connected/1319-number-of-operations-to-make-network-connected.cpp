class Solution {
public:
    int find(int node, vector<int>& parent){
        if(node == parent[node]) return node;

        return parent[node] = find(parent[node], parent);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> parent(n);
        vector<int> size(n, 1);
        for(int i = 0; i<n; i++){
            parent[i] = i;
        }

        int components = n;

        if(connections.size() < n-1) return -1;

        for(int i = 0; i < connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];
            int pu = find(u, parent);
            int pv = find(v, parent);

            if(pu == pv) continue;
            if(size[pu] < size[pv]){
                parent[pu] = pv;
                size[pv] += size[pu];
                components--;
            } else {
                parent[pv] = pu;
                size[pu] += size[pv];
                components--;
            }
        }

        return components-1;
    }
};