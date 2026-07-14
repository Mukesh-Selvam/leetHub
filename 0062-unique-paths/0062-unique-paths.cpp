/*
class Solution{
public:
    int uniquePaths(int m, int n) {
    int totalMoves = m + n - 2;
    int k = min(m - 1, n - 1); 
    long long res = 1;
    for (int i = 1; i <= k; ++i) {
        res = res * (totalMoves - k + i) / i;
    }

    return (int)res;
    }
};
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return paths(m-1,n-1,dp);
    }
    int paths(int i,int j,vector<vector<int>>& dp){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int l=paths(i,j-1,dp);
        int u=paths(i-1,j,dp);
        return dp[i][j]=l+u;
    }
};