class Solution {
public:
    int countSubstrings(string s, string t) {
        int m = s.length(), n = t.length();
        int ans = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (s[i] != t[j]) {
                    int left = 0;
                    while (i - 1 - left >= 0 && j - 1 - left >= 0 && s[i - 1 - left] == t[j - 1 - left]) {
                        left++;
                    }
                    
                    int right = 0;
                    while (i + 1 + right < m && j + 1 + right < n && s[i + 1 + right] == t[j + 1 + right]) {
                        right++;
                    }
                    
                    ans += (left + 1) * (right + 1);
                }
            }
        }
        
        return ans;
    }
};