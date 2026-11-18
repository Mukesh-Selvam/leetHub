class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_val = nums[0], moves = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < min_val) {
                min_val = nums[i];
            }
        }
        for (int num : nums) {
            moves += num - min_val;
        }
        return moves;
    }
};
