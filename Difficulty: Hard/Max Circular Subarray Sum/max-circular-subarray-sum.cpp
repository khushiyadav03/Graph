class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        int rollingSum = 0;
        int globalMax = arr[0];
        int rollingSum2 = 0;
        int globalMin = arr[0];
        int total = 0;

        for(int i = 0; i < arr.size(); i++){
            total += arr[i];

            // Max Kadane
            rollingSum += arr[i];
            globalMax = max(globalMax, rollingSum);
            rollingSum = max(rollingSum, 0);

            // Min Kadane
            rollingSum2 += arr[i];
            globalMin = min(globalMin, rollingSum2);
            rollingSum2 = min(rollingSum2, 0);
        }

        if(globalMax < 0) return globalMax;

        return max(globalMax, total - globalMin);
    }
};