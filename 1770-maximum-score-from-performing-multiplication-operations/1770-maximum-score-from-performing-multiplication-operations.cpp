class Solution {
public:
    int solve(int i, int left, vector<int>& nums, vector<int>& multipliers, vector<vector<int>>& dp){
        int m = multipliers.size();
        int n = nums.size();
        
        if(i == m) return 0;
        
        if(dp[i][left] != INT_MIN) return dp[i][left];
        
        int right = n - 1 - (i - left);
        
        int pickLeft = multipliers[i] * nums[left] +
                       solve(i + 1, left + 1, nums, multipliers, dp);
        
        int pickRight = multipliers[i] * nums[right] +
                        solve(i + 1, left, nums, multipliers, dp);
        
        return dp[i][left] = max(pickLeft, pickRight);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m = multipliers.size();
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, INT_MIN));
        return solve(0, 0, nums, multipliers, dp);
    }
};