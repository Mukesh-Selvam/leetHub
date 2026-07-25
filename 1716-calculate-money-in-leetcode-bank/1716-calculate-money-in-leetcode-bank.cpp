class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int rem_days = n % 7;
        
        int total_weeks = 28 * weeks + (7 * weeks * (weeks - 1)) / 2;
        int total_rem = rem_days * weeks + (rem_days * (rem_days + 1)) / 2;
        
        return total_weeks + total_rem;
    }
};