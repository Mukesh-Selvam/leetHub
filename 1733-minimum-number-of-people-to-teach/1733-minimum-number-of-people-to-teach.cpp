#include <vector>
#include <bitset>
#include <algorithm>

class Solution {
public:
    int minimumTeachings(int n, std::vector<std::vector<int>>& languages, std::vector<std::vector<int>>& friendships) {
        int m = languages.size();
        std::vector<std::bitset<501>> user_langs(m + 1);
        for (int i = 0; i < m; ++i) {
            for (int l : languages[i]) {
                user_langs[i + 1].set(l);
            }
        }

        std::vector<bool> needs_teaching(m + 1, false);
        int problem_users_count = 0;
        for (const auto& f : friendships) {
            int u = f[0], v = f[1];
            if ((user_langs[u] & user_langs[v]).none()) {
                if (!needs_teaching[u]) {
                    needs_teaching[u] = true;
                    problem_users_count++;
                }
                if (!needs_teaching[v]) {
                    needs_teaching[v] = true;
                    problem_users_count++;
                }
            }
        }

        if (problem_users_count == 0) return 0;
        std::vector<int> lang_count(n + 1, 0);
        int max_known = 0;

        for (int u = 1; u <= m; ++u) {
            if (needs_teaching[u]) {
                for (int l : languages[u - 1]) {
                    lang_count[l]++;
                    max_known = std::max(max_known, lang_count[l]);
                }
            }
        }
        return problem_users_count - max_known;
    }
};