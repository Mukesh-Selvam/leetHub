class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        int n = queries.size();
        vector<int> bit(n + m + 1, 0);
        vector<int> pos(m + 1);

        auto update = [&](int idx, int val) {
            for (; idx <= n + m; idx += idx & -idx)
                bit[idx] += val;
        };

        auto query = [&](int idx) {
            int sum = 0;
            for (; idx > 0; idx -= idx & -idx)
                sum += bit[idx];
            return sum;
        };

        for (int i = 1; i <= m; ++i) {
            pos[i] = n + i;
            update(n + i, 1);
        }

        vector<int> ans;
        ans.reserve(n);
        int cur_head = n;

        for (int q : queries) {
            int p = pos[q];
            ans.push_back(query(p - 1));
            update(p, -1);
            pos[q] = cur_head;
            update(cur_head, 1);
            cur_head--;
        }

        return ans;
    }
};