class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> week = {
            "Sunday", "Monday", "Tuesday", "Wednesday",
            "Thursday", "Friday", "Saturday"};
vector<int> days = {31,28,31,30,31,30,31,31,30,31,30,31};
int total = 0;
for (int y = 1971; y < year; y++) {
            total += 365;
            if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0))
                total++;}
 for (int m = 1; m < month; m++) {
            total += days[m - 1];
            if (m == 2 && ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)))
                total++;}
        total += day - 1;
        return week[(total + 5) % 7];
    }
};