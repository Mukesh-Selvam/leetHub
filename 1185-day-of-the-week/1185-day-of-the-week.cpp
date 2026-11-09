class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> days = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        vector<int> months = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        int totalDays = day;
        for (int y = 1971; y < year; ++y) {
            totalDays += ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) ? 366 : 365;
        }
        
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            months[2] = 29;
        }
        
        for (int m = 1; m < month; ++m) {
            totalDays += months[m];
        }
        
        return days[(totalDays + 4) % 7];
    }
};