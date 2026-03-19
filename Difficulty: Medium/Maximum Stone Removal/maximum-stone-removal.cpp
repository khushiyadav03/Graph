class DSU{
    public:
    vector<int> parent, size;
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);
        
        for(int i = 1; i<=n; i++) parent[i] = i;
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
    int maxRemove(vector<vector<int>>& stones) {
        int maxRow = 0, maxCol = 0;
        for(auto it : stones){
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        
        DSU dsu(maxRow + maxCol + 1);
        unordered_set<int> usedNode;
        
        for(auto it : stones){
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1; 
            
            dsu.UnionBySize(nodeRow, nodeCol);
            usedNode.insert(nodeRow);
            usedNode.insert(nodeCol);
        }
        
        int component = 0;
        for(int node : usedNode){
            if(dsu.find(node) == node) component++;
        }
        
        return stones.size() - component;
    }
};