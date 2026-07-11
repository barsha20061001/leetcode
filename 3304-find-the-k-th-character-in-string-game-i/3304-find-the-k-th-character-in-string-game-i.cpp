class Solution {
public:
    char kthCharacter(int k) {

        string word = "a"; // Initially, word = "a"

        while (word.size() < k) {

            string temp = "";

            for (char c : word) {
                temp += char(c + 1); // Replace every character with the next alphabet letter.
            }

            word += temp; // Append the generated string to the original.
        }

        return word[k - 1]; // Strings are 0-indexed, but the problem asks for the k-th character.
    }
};