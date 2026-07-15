class Solution {
public:
    // int minDistance(string word1, string word2) {
    //     int m=word1.size(),n=word2.size();
    //     vector<vector<int>>dp(m,vector<int>(n,-1));
    //     return edit(m-1,n-1,word1,word2,dp);
    // }
    // int edit(int i,int j,string& word1,string& word2,vector<vector<int>>& dp){
    //     if(i<0) return j+1;
    //     if(j<0) return i+1;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(word1[i]==word2[j]){
    //         return dp[i][j]=edit(i-1,j-1,word1,word2,dp);
    //     }else{
    //         int ins=1+edit(i,j-1,word1,word2,dp);
    //         int del=1+edit(i-1,j,word1,word2,dp);
    //         int rep=1+edit(i-1,j-1,word1,word2,dp);
    //         return dp[i][j]=min({ins,del,rep});
    //     }

    // }
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1));
        for(int j=0;j<=n;j++){
            dp[0][j]=j;
        }
        for(int i=0;i<=m;i++){
            dp[i][0]=i;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    int ins=1+dp[i][j-1];
                    int del=1+dp[i-1][j];
                    int rep=1+dp[i-1][j-1];
                    dp[i][j]=min({ins,del,rep});
                }
            }
        }
        return dp[m][n];
    }
};