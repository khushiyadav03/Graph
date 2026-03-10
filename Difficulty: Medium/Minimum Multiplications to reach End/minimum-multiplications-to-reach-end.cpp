// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int mod = 100000;
        vector<int> dist(100000, INT_MAX);
        dist[start] = 0;
        
        queue<pair<int, int>> q;
        q.push({start, 0});
        
        if(start == end) return 0;
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int node = it.first;
            int steps = it.second;
            
            for(int i = 0; i<arr.size(); i++){
                int next = (node * arr[i]) % mod;
                
                if(next == end) return steps+1;
                
                if(steps+1 < dist[next]){
                    dist[next] = steps+1;
                    q.push({next, steps+1});
                }
            }
        }
        return -1;
    }
};
