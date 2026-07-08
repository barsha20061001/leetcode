class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1; // Since indexing starts from 0, the last index is size()-1.
        int j = b.size() - 1;
        int carry = 0;  // Initially there is no carry.
        string ans = ""; // to store answer  in empty string 

        while (i >= 0 || j >= 0 || carry) {  // Continue the loop as long as , there are digits left in a, digits left in b or  carry is still present.
            int sum = carry;  // Start the current sum with the carry from the previous addition.

            if (i >= 0)   // Only add a digit from a if one exists, Because one string may be longer.
                sum += a[i--] - '0'; // Add the current binary digit from a to sum, then move one position left.

            if (j >= 0)
                sum += b[j--] - '0';

            ans += (sum % 2)/**gives the last binary digit **/ + '0'; // converts integer back into character.
            carry = sum / 2; // Now calculate the carry.
        }

        reverse(ans.begin(), ans.end()); // rreverse the ans 
        return ans;
    }
};