#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isValid(const string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') {
                count++;
            } else if (c == ')') {
                count--;
                if (count < 0) return false;
            }
        }
        return count == 0;
    }

    void rempar(string s, int index, int left_rem, int right_rem, vector<string>& result) {
        if (left_rem == 0 && right_rem == 0) {
            if (isValid(s)) {
                result.push_back(s);
            }
            return;
        }

        for (int i = index; i < s.length(); i++) {
            if (i > index && s[i] == s[i - 1]) {
                continue;
            }

            if (left_rem > 0 && s[i] == '(') {
                rempar(s.substr(0, i) + s.substr(i + 1), i, left_rem - 1, right_rem, result);
            }
            if (right_rem > 0 && s[i] == ')') {
                rempar(s.substr(0, i) + s.substr(i + 1), i, left_rem, right_rem - 1, result);
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int left_rem = 0, right_rem = 0;
        for (char c : s) {
            if (c == '(') {
                left_rem++;
            } else if (c == ')') {
                if (left_rem > 0) {
                    left_rem--;
                } else {
                    right_rem++;
                }
            }
        }

        vector<string> result;
        rempar(s, 0, left_rem, right_rem, result);
        return result;
    }
};