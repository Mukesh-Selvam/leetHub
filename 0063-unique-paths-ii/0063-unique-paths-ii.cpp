class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obg) {
        int m = obg.size();
        int n = obg[0].size();
        
        if (obg[0][0] == 1) return 0;
        
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        dp[0][0] = 1;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obg[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    if (i > 0) dp[i][j] += dp[i - 1][j];
                    if (j > 0) dp[i][j] += dp[i][j - 1];
                }
            }
        }
        
        return dp[m - 1][n - 1];
    }
};