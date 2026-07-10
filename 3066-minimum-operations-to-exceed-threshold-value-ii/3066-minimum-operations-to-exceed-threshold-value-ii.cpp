class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>>pq(nums.begin(),nums.end());
        int op=0;
        while(!pq.empty() && pq.top()<k){
            long long a1=pq.top();
            pq.pop();
            long long a2=pq.top();
            pq.pop();
            pq.push(((a1*2)+a2));
            op++;
        }
        return op;
    }
};