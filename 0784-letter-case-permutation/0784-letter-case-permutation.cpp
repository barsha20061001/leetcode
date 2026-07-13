class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;

        function<void(int)> solve = [&](int index) {
            // Creates a recursive (backtracking) function.
          // index tells which character we are currently processing.
         // [&] means capture ans and s by reference.
            if (index == s.size()) {
                ans.push_back(s);
                return;
            }

            if (isdigit(s[index])) {
                // Checks whether the current character is a digit.
                solve(index + 1); // Simply move to the next character.
            } else {
                s[index] = tolower(s[index]); // Convert it to lowercase.
                solve(index + 1); // Recursively process the remaining characters.

                s[index] = toupper(s[index]);
                solve(index + 1);
            }
        };

        solve(0);
        return ans;
    }
};