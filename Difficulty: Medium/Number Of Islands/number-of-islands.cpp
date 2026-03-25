class DSU {
    public :
    vector<int> parent, size;
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);
        
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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        vector<vector<int>> visited(n, vector<int>(m, 0));
        DSU dsu(n*m);
        vector<int> ans;
        int count = 0;
        
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        
        for(int i = 0; i<operators.size(); i++){
            int r = operators[i][0];
            int c = operators[i][1];
            
            if(visited[r][c] == 1){
                ans.push_back(count);
                continue;
            }
            
            visited[r][c] = 1;
            count++;
            
            int node = r * m + c;
            
            for(int k = 0; k<4; k++){
                int nr = r + dx[k];
                int nc = c + dy[k];
                
                if(nr >=0 && nr <n && nc >=0 && nc < m && visited[nr][nc] == 1){
                    int adjNode = nr *m + nc;
                    
                    if(dsu.find(node) != dsu.find(adjNode)){
                        dsu.UnionBySize(node, adjNode);
                        count--;
                    }
                }
            }
            ans.push_back(count);
            
        }
        return ans;
    }
};
