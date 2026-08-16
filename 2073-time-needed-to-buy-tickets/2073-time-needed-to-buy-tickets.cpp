class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int total_time = 0;
        int target = tickets[k];
        
        for (int i = 0; i < tickets.size(); ++i) {
            if (i <= k) {
                total_time += min(tickets[i], target);
            } else {
                total_time += min(tickets[i], target - 1);
            }
        }
        
        return total_time;
    }
};