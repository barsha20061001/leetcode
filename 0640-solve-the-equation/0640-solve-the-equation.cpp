class Solution {
public:
    string solveEquation(string equation) {
        auto parse = [](const string& expression) {
            int coefficient = 0;
            int constant = 0;
            int sign = 1;

            for (int i = 0; i < expression.size();) {
                if (expression[i] == '+') {
                    sign = 1;
                    i++;
                } else if (expression[i] == '-') {
                    sign = -1;
                    i++;
                } else {
                    int number = 0;
                    bool hasNumber = false;

                    while (i < expression.size() && isdigit(expression[i])) {
                        number = number * 10 + (expression[i] - '0');
                        hasNumber = true;
                        i++;
                    }

                    if (i < expression.size() && expression[i] == 'x') {
                        coefficient += sign * (hasNumber ? number : 1);
                        i++;
                    } else {
                        constant += sign * number;
                    }
                }
            }

            return pair<int, int>{coefficient, constant};
        };

        int equalPosition = equation.find('=');

        auto left = parse(equation.substr(0, equalPosition));
        auto right = parse(equation.substr(equalPosition + 1));

        int coefficient = left.first - right.first;
        int constant = right.second - left.second;

        if (coefficient == 0) {
            return constant == 0 ? "Infinite solutions" : "No solution";
        }

        return "x=" + to_string(constant / coefficient);
    }
};