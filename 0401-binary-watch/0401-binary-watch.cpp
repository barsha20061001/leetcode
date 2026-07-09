class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;  // Create answer vector

        for (int h = 0; h < 12; h++) { // Loop through every hour
            for (int m = 0; m < 60; m++) { // Loop through every minute

                if (__builtin_popcount(h) /* returns the number of 1s in binary. */ + __builtin_popcount(m) == turnedOn) { // counts the LEDs used by minutes.

                // If total LEDs ON equals turnedOn store this time.

                    string time = to_string(h) + ":";  // Build string

                    if (m < 10)  // Add leading zero
                        time += "0";

                    time += to_string(m); // Append minutes

                    ans.push_back(time); // Store
                }
            }
        }

        return ans;
    }
};