class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        if (num.empty()) return res;
        solve(0, 0, 0, "", num, res, target);
        return res;
    }

    void solve(int i, long count, long prev, string ans, string &nums, vector<string> &res, int target) {
        if (nums.length() == i) {
            if (count == target) {
                res.push_back(ans);
            }
            return;
        }

        for (int j = i; j < nums.length(); j++) {
            if (j > i && nums[i] == '0') break;

            string part = nums.substr(i, j - i + 1);
            long cur = stol(part);
            if (i == 0) {
                solve(j + 1, cur, cur, part, nums, res, target);
            } else {
                solve(j + 1, (count - prev) + (prev * cur), prev * cur, ans + '*' + part, nums, res, target);
                solve(j + 1, count + cur, cur, ans + '+' + part, nums, res, target);
                solve(j + 1, count - cur, -cur, ans + '-' + part, nums, res, target);
            }
        }
    }
};