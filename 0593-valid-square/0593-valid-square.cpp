#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    int getDist(vector<int>& p1, vector<int>& p2) {
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int dists[6] = {
            getDist(p1, p2), getDist(p1, p3), getDist(p1, p4),
            getDist(p2, p3), getDist(p2, p4), getDist(p3, p4)
        };
        
        sort(dists, dists + 6);
        
        return dists[0] > 0 && 
               dists[0] == dists[1] && 
               dists[0] == dists[2] && 
               dists[0] == dists[3] && 
               dists[4] == dists[5];
    }
};