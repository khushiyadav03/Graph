class Solution {
  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        if(n == 1) return 0;
        
        int prev1 = 0, prev2 = 0;
        
        for(int i = 1; i<n; i++){
            int jumptwo = INT_MAX;
            int jumpone = prev1 + abs(height[i] - height[i-1]);
            
            if(i > 1) jumptwo = prev2 + abs(height[i] - height[i-2]);
            
            int curr = min(jumpone, jumptwo);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};