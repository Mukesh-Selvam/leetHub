class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>temp;
        int cs=0;
        solve(0,cs,res,temp,candidates,target);
        return res;
    }
    void solve(int i,int cs,vector<vector<int>>& res,vector<int>& temp,vector<int>& candidates,int& target){
            if(cs==target){
                res.push_back(temp);
                return;
            }
        
        if(cs>target || i==candidates.size()){
            return;
        }
        temp.push_back(candidates[i]);
        solve(i,cs+candidates[i],res,temp,candidates,target);
        temp.pop_back();
         solve(i+1,cs,res,temp,candidates,target);
    }
};
