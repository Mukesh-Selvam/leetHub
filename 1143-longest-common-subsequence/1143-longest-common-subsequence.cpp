/*
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(),n=text2.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return lcs(m-1,n-1,text1,text2,dp);
    }
    int lcs(int i,int j,string& s1,string& s2, vector<vector<int>>& dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]=1+lcs(i-1,j-1,s1,s2,dp);
        }else{
            int l=lcs(i,j-1,s1,s2,dp);
            int r=lcs(i-1,j,s1,s2,dp);
            return dp[i][j]=max(l,r);
        }
    }
};
*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        
        // Create a 2D table of size (m+1) x (n+1) initialized to 0.
        // dp[i][j] represents the LCS of text1[0...i-1] and text2[0...j-1].
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // Build the table from the bottom up
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // If characters match, add 1 to the result of excluding both characters
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } 
                // If they don't match, take the maximum by ignoring one character at a time
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        // The final answer is stored at the bottom-right corner of the table
        return dp[m][n];
    }
};
