class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int totalTime = 0;
        for (size_t i = 0; i < points.size() - 1; ++i) {
            int dx = abs(points[i + 1][0] - points[i][0]);
            int dy = abs(points[i + 1][1] - points[i][1]);
            totalTime += max(dx, dy);
        }
        return totalTime;
    }
};