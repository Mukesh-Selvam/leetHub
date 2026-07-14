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