#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 1; i <= n; i++) parent[i] = i;
    }

    int find(int node) {
        if (node == parent[node]) return node;
        return parent[node] = find(parent[node]);
    }

    void UnionBySize(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = parent[pv];
            size[pv] += size[pu];
        } else {
            parent[pv] = parent[pu];
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, int> mapMailNode;
        DSU dsu(n);
        
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (mapMailNode.find(mail) == mapMailNode.end()) {
                    mapMailNode[mail] = i;
                } else {
                    dsu.UnionBySize(i, mapMailNode[mail]);
                }
            }
        }

        vector<vector<string>> mergeMail(n);
        for (auto it : mapMailNode) {
            string mail = it.first;
            int node = dsu.find(it.second);
            mergeMail[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (mergeMail[i].size() == 0) continue;
            
            sort(mergeMail[i].begin(), mergeMail[i].end());
            
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : mergeMail[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};