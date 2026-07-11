class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + nums[i];
        }
        int totalSum = 0;
        for (int i = 0; i < n; ++i) {
            int start = max(0, i - nums[i]);
            totalSum += (pref[i + 1] - pref[start]);
        }
        return totalSum;
    }
};