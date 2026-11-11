class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
       
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int maxLen = 0;

        for (int i = 2; i < n; ++i) {
            int left = 0, right = i - 1;
            
            while (left < right) {
                int sum = arr[left] + arr[right];
                
                if (sum < arr[i]) {
                    ++left;
                } else if (sum > arr[i]) {
                    --right;
                } else {
                    dp[right][i] = (dp[left][right] > 0 ? dp[left][right] : 2) + 1;
                    maxLen = max(maxLen, dp[right][i]);
                    ++left;
                    --right;
                }
            }
        }

        return maxLen;
    }
};