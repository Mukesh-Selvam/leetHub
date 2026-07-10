class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        long long score = 0;
        for (int i = 0; i < k; i++) {
            int val = pq.top();
            pq.pop();
            score += val;
            pq.push((val + 2) / 3);
        }
        return score;
    }
};