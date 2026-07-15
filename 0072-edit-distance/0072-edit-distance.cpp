class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return edit(m-1,n-1,word1,word2,dp);
    }
    int edit(int i,int j,string& word1,string& word2,vector<vector<int>>& dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]){
            return dp[i][j]=edit(i-1,j-1,word1,word2,dp);
        }else{
            int ins=1+edit(i,j-1,word1,word2,dp);
            int del=1+edit(i-1,j,word1,word2,dp);
            int rep=1+edit(i-1,j-1,word1,word2,dp);
            return dp[i][j]=min({ins,del,rep});
        }

    }
};