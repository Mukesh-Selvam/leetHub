class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int zeros = 0;
        int left = 0;

        for (; left < n - zeros; ++left) {
            if (arr[left] == 0) {
                if (left == n - zeros - 1) {
                    arr[n - 1] = 0;
                    --n;
                    break;
                }
                ++zeros;
            }
        }

        int right = n - 1;
        --left;

        while (left >= 0) {
            if (arr[left] == 0) {
                arr[right--] = 0;
                arr[right--] = 0;
            } else {
                arr[right--] = arr[left];
            }
            --left;
        }
    }
};