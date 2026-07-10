class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq(amount.begin(), amount.end());
        int time = 0;
        while (!pq.empty()) {
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            if (a == 0) {
                break;
            }
            if (b == 0) {
                time += a;
                break;
            }
            a--;
            b--;
            time++;
            pq.push(a);
            pq.push(b);
        }
        
        return time;
    }
};