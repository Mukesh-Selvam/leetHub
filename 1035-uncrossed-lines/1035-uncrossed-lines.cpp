class Solution {
public:
    /*
    tabulation:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return ucl(n1-1,n2-1,nums1,nums2,dp);
    }
    int ucl(int i,int j,vector<int>& nums1,vector<int>& nums2,vector<vector<int>>& dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(nums1[i]==nums2[j]){
            return dp[i][j]=1+ucl(i-1,j-1,nums1,nums2,dp);
        }else{
            int l=ucl(i,j-1,nums1,nums2,dp);
            int r=ucl(i-1,j,nums1,nums2,dp);
            return dp[i][j]=max(l,r);
        }
    }
    */
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2){
        int m=nums1.size();
        int n=nums2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    int l=dp[i][j-1];
                    int r=dp[i-1][j];
                    dp[i][j]=max(l,r);
                }
            }
        }
        return dp[m][n];

    }
};