class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        if (timePoints.size() > 1440) return 0;

        vector<bool> seen(1440, false);
        for (const string& time : timePoints) {
            int minutes = ((time[0] - '0') * 10 + (time[1] - '0')) * 60 + 
                          ((time[3] - '0') * 10 + (time[4] - '0'));
            if (seen[minutes]) return 0;
            seen[minutes] = true;
        }

        int first = -1, prev = -1, minDiff = 1440;
        for (int i = 0; i < 1440; ++i) {
            if (seen[i]) {
                if (first == -1) {
                    first = i;
                } else {
                    minDiff = min(minDiff, i - prev);
                }
                prev = i;
            }
        }

        return min(minDiff, 1440 - prev + first);
    }
};