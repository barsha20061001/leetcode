class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;

        string current = "";
        int number = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                number = number * 10 + (ch - '0');
            }
            else if (ch == '[') {
                countStack.push(number);
                stringStack.push(current);

                number = 0;
                current = "";
            }
            else if (ch == ']') {
                int repeat = countStack.top();
                countStack.pop();

                string previous = stringStack.top();
                stringStack.pop();

                while (repeat--)
                    previous += current;

                current = previous;
            }
            else {
                current += ch;
            }
        }

        return current;
    }
};