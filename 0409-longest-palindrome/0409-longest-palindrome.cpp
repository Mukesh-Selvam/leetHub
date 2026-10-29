class Solution {
public:
    int longestPalindrome(string s) {
        int count[128] = {0};
        for (char c : s) {
            count[c]++;
        }
        
        int length = 0;
        for (int i = 0; i < 128; i++) {
            length += (count[i] / 2) * 2;
        }
        
        return length < s.length() ? length + 1 : length;
    }
};