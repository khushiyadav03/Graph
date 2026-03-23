class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int node) {
        if(node == parent[node]) return node;
        return parent[node] = find(parent[node]); // path compression
    }

    void UnionBySize(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if(pu == pv) return;

        if(size[pu] < size[pv]) {
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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {

        DSU dsu(n * m);
        vector<vector<int>> visited(n, vector<int>(m, 0));

        vector<int> ans;
        int count = 0;

        vector<pair<int,int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        for(auto &op : operators) {
            int r = op[0];
            int c = op[1];

            // if already land
            if(visited[r][c] == 1) {
                ans.push_back(count);
                continue;
            }

            // mark land
            visited[r][c] = 1;
            count++;

            int node = r * m + c;

            // check 4 directions
            for(auto &d : dir) {
                int newRow = r + d.first;
                int newCol = c + d.second;

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
                    if(visited[newRow][newCol] == 1) {
                        int adjNode = newRow * m + newCol;

                        if(dsu.find(node) != dsu.find(adjNode)) {
                            dsu.UnionBySize(node, adjNode);
                            count--;
                        }
                    }
                }
            }

            ans.push_back(count);
        }

        return ans;
    }
};