class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int count=0,ans=0;
        findsum(0,nums,target,count,ans);
        return ans;
    }
    void findsum(int i,vector<int>& nums,int target,int count,int& ans){
        if(i==nums.size()){
            if(count==target) ans++;
            return;
        }
        findsum(i+1,nums,target,count+nums[i],ans);
        findsum(i+1,nums,target,count-nums[i],ans);
    }
};