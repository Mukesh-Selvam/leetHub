class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(k, 0);

        for (int i = n - 1; i >= 0; --i) {
            int currMax = 0;
            int maxSum = 0;
            
            for (int j = 1; j <= k && i + j <= n; ++j) {
                currMax = max(currMax, arr[i + j - 1]);
                int nextSum = (i + j == n) ? 0 : dp[(i + j) % k];
                int sum = (currMax * j) + nextSum;
                maxSum = max(maxSum, sum);
            }
            
            dp[i % k] = maxSum;
        }

        return dp[0];
    }
};