class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int free = 0;
        int hold = -prices[0];
        
        for (int p : prices) {
            free = max(free, hold + p - fee);
            hold = max(hold, free - p);
        }
        
        return free;
    }
};