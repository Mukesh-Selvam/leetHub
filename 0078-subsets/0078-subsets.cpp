class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>temp;
        findsubset(0,nums,temp,res);
        return res;
    }
    void findsubset(int i,vector<int>& nums,vector<int>& temp,vector<vector<int>>& res){
        if(i==nums.size()){
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        findsubset(i+1,nums,temp,res);

        temp.erase(temp.begin()+(temp.size()-1));
        findsubset(i+1,nums,temp,res);

    }
};