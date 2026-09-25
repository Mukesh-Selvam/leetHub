

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int maxTime = 0;
        vector<int> memo(n, -1);
        
        for (int i = 0; i < n; i++) {
            if (informTime[i] == 0) {
                maxTime = max(maxTime, dfs(i, manager, informTime, memo));
            }
        }
        
        return maxTime;
    }
    
private:
    int dfs(int i, const vector<int>& manager, const vector<int>& informTime, vector<int>& memo) {
        if (manager[i] == -1) {
            return 0;
        }
        if (memo[i] != -1) {
            return memo[i];
        }
        
        memo[i] = informTime[manager[i]] + dfs(manager[i], manager, informTime, memo);
        return memo[i];
    }
};