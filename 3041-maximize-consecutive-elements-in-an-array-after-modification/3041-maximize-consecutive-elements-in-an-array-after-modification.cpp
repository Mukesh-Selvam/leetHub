#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> dp;
        int ans = 0;

        for (int x : nums) {
            int inc = dp[x] + 1;
            dp[x + 1] = max(dp[x + 1], inc);
            ans = max(ans, dp[x + 1]);

            int keep = dp[x - 1] + 1;
            dp[x] = max(dp[x], keep);
            ans = max(ans, dp[x]);
        }

        return ans;
    }
};