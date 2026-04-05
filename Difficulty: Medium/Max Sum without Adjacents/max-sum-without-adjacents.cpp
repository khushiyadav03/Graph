// User function template for C++
class Solution {
  public:
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n+2, 0);
        
        for(int i = n-1; i>=0; i--){
            int pick = arr[i] + dp[i+2];
            int skip = dp[i+1];
            
            dp[i] = max(pick, skip);
        }
        
        return dp[0];
    }
};