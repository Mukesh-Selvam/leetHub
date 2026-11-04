#include <vector>
#include <utility>

class Solution {
public:
    int findNumberOfLIS(std::vector<int>& nums) {
        if (nums.empty()) return 0;

        std::vector<std::vector<std::pair<int, int>>> decks;

        for (int x : nums) {
            int l = 0, r = decks.size();
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (decks[mid].back().first >= x) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            int deck_idx = l;

            int count = 0;
            if (deck_idx == 0) {
                count = 1;
            } else {
                const auto& prev_deck = decks[deck_idx - 1];
                int low = 0, high = prev_deck.size();
                while (low < high) {
                    int mid = low + (high - low) / 2;
                    if (prev_deck[mid].first < x) {
                        high = mid;
                    } else {
                        low = mid + 1;
                    }
                }
                int total_sum = prev_deck.back().second;
                int excluded_sum = (low > 0) ? prev_deck[low - 1].second : 0;
                count = total_sum - excluded_sum;
            }

            if (deck_idx < decks.size()) {
                int new_cum_count = count + decks[deck_idx].back().second;
                decks[deck_idx].push_back({x, new_cum_count});
            } else {
                decks.push_back({{x, count}});
            }
        }

        return decks.back().back().second;
    }
};