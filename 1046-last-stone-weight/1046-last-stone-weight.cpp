class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones) {
        std::priority_queue<int> max_heap(stones.begin(), stones.end());
        
        while (max_heap.size() > 1) {
            int y = max_heap.top();
            max_heap.pop();
            int x = max_heap.top();
            max_heap.pop();
            
            if (x != y) {
                max_heap.push(y - x);
            }
        }
        
        return max_heap.empty() ? 0 : max_heap.top();
    }
};