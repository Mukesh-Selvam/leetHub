class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> record;
        record.reserve(operations.size());
        
        for (const string& op : operations) {
            if (op == "+") {
                int n = record.size();
                record.push_back(record[n - 1] + record[n - 2]);
            } else if (op == "D") {
                record.push_back(record.back() * 2);
            } else if (op == "C") {
                record.pop_back();
            } else {
                record.push_back(stoi(op));
            }
        }
        
        int totalSum = 0;
        for (int score : record) {
            totalSum += score;
        }
        return totalSum;
    }
};