class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int>temp;
        return countsubsets(0,nums,temp,k)-1;
    }
    int countsubsets(int i,vector<int>& nums,vector<int>& temp,int k){
        if(i==nums.size()){
            return 1;
        }
        int pick=0;
        if(!ranges::contains(temp,(nums[i]+k)) && !ranges::contains(temp,(nums[i]-k))){
            temp.push_back(nums[i]);
            pick=countsubsets(i+1,nums,temp,k);
            temp.pop_back();
        }
        int np=countsubsets(i+1,nums,temp,k);
        return pick+np;
    }
};