class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> result;
        for (int i = 1; i <= 9; ++i) {
            dfs(n, k, 1, i, result);
        }
        return result;
    }
    
private:
    void dfs(int n, int k, int length, int current_num, vector<int>& result) {
        if (length == n) {
            result.push_back(current_num);
            return;
        }
        int last_digit = current_num % 10;
        unordered_set<int> next_digits = {last_digit + k, last_digit - k};
        
        for (int next_digit : next_digits) {
            if (next_digit >= 0 && next_digit <= 9) {
                dfs(n, k, length + 1, current_num * 10 + next_digit, result);
            }
        }
    }
};