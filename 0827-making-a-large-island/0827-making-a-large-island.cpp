class DSU{
    public:
    vector<int> parent, size;
    DSU(int n){
        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i<n; i++) parent[i] = i;
    }

    int find(int node){
        if(node == parent[node]) return node;

        return parent[node] = find(parent[node]);
    }

    void UnionBySize(int u, int v){
        int pu = find(u);
        int pv = find(v);

        if(pu == pv) return;

        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU dsu(n*n);

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0,0,1, -1};

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 0) continue;

                for(int k = 0; k<4; k++){
                    int nr = i + dx[k];
                    int nc = j + dy[k];

                    if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1){
                        int node = i * n + j;
                        int adjNode = nr *n +nc;
                        dsu.UnionBySize(node, adjNode);
                    }
                }
            }
        }

        int maxSize = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 0){
                    set<int> parents;
                    for(int k = 0; k<4; k++){
                        int nr = i + dx[k];
                        int nc = j + dy[k];
                        if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1){
                            int adjNode = nr *n +nc;
                            int parent = dsu.find(adjNode);
                            parents.insert(parent);
                        }
                    }

                    int newSize = 1;
                    for(auto p : parents) newSize += dsu.size[p];

                    maxSize = max(maxSize, newSize);
                }
            }
        }

        for(int i = 0; i < n*n; i++){
            maxSize = max(maxSize, dsu.size[dsu.find(i)]);
        }

        return maxSize;
    }
};