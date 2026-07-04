class Solution {
public:
    set<vector<int>> st;

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        st.clear();
        find(0, temp, res, nums);
        return res;
    }

    void find(int i, vector<int>& temp, vector<vector<int>>& res, vector<int>& nums) {
        if (i == nums.size()) {
            if (temp.size() >= 2 && st.find(temp) == st.end()) {
                res.push_back(temp);
                st.insert(temp);
            }
            return;
        }

        if (temp.size() == 0) {
            temp.push_back(nums[i]);
            find(i + 1, temp, res, nums);
            temp.pop_back();
            find(i + 1, temp, res, nums);
        } else if (temp[temp.size() - 1] <= nums[i]) {
            temp.push_back(nums[i]);
            find(i + 1, temp, res, nums);
            temp.pop_back();
            find(i + 1, temp, res, nums);
        } else {
            find(i + 1, temp, res, nums);
        }
    }

};