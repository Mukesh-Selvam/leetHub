class Solution {
public:
    int minSwaps(string s) {
        int i = 0, j = s.size() - 1;
        int balance = 0, swaps = 0;

        while (i < j) {
            if (s[i] == '[') balance++;
            else balance--;

            if (balance < 0) {
                while (i < j && s[j] != '[') j--;
                swap(s[i], s[j]);
                swaps++;
                balance = 1;
                j--;
            }
            i++;
        }
        return swaps;
    }
};
