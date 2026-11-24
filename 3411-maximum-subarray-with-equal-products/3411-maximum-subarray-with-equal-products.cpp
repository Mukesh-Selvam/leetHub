#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            long long prod = 1;
            int g = 0;
            long long l = 1;

            for (int j = i; j < n; ++j) {
                int x = nums[j];
                if (prod > LLONG_MAX / x) {
                    break;
                }
                prod *= x;
                g = (j == i) ? x : std::gcd(g, x);
                l = std::lcm(l, static_cast<long long>(x));

                if (l > LLONG_MAX / g) {
                    break;
                }
                if (prod == l * g) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};