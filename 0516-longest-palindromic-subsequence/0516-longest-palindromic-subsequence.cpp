/*
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        return lps(0,n-1,s);
    }
    int lps(int i,int j,string& s){
        if(i>j) return 0;
        if(i==j) return 1;
        if(s[i]==s[j]){
            return 2+lps(i+1,j-1,s);
        }else{
            int l=lps(i,j-1,s);
            int r=lps(i+1,j,s);
            return max(l,r);
        }
    }
};

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return lps(0,n-1,s,dp);
    }
    int lps(int i,int j,string& s,vector<vector<int>>& dp){  //TC-O(N^2)  SC-O(N^2)+O(N)
        if(i>j) return 0;
        if(i==j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]){
            return dp[i][j]=2+lps(i+1,j-1,s,dp);
        }else{
            int l=lps(i,j-1,s,dp);
            int r=lps(i+1,j,s,dp);
            return dp[i][j]=max(l,r);
        }
    }
};
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        for(int len=2;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j=i+len-1;
                if(s[i]==s[j]){
                    dp[i][j]=2+dp[i+1][j-1];
                }else{
                    int l=dp[i][j-1];
                    int r=dp[i+1][j];
                    dp[i][j]=max(l,r);
                }
            }
        }
        return dp[0][n-1];
    }
};
*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
                }
            }
        }
        
        return dp[0][n - 1];
    }
};