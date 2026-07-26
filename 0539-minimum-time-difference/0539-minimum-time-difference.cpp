class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;

        for (const string& time : timePoints) {
            int hour = stoi(time.substr(0, 2));
            int minute = stoi(time.substr(3, 2));
            minutes.push_back(hour * 60 + minute);
        }

        sort(minutes.begin(), minutes.end());

        int answer = 1440;

        for (int i = 1; i < minutes.size(); i++)
            answer = min(answer, minutes[i] - minutes[i - 1]);

        answer = min(answer, 1440 - minutes.back() + minutes.front());

        return answer;
    }
};