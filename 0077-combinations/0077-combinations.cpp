class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>res;
        vector<int>arr;
        for(int i=0;i<n;i++){
            arr.push_back(i+1);
        }
        vector<int>temp;
        com(0,temp,arr,res,k);
        return res;
    }
    void com(int i,vector<int>& temp,vector<int>& arr,vector<vector<int>>& res,int target){
        if(target==temp.size()){
            res.push_back(temp);
            return;
        }
        if(i==arr.size()) return;
        temp.push_back(arr[i]);
         com(i+1,temp,arr,res,target);
         temp.pop_back();
          com(i+1,temp,arr,res,target);
    }
};