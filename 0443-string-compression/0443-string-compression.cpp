class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0;
        int read = 0;

        while (read < n) {
            char current = chars[read];
            int start = read;

            while (read < n && chars[read] == current) {
                read++;
            }

            int count = read - start;
            chars[write++] = current;

            if (count > 1) {
                string frequency = to_string(count);

                for (char digit : frequency) {
                    chars[write++] = digit;
                }
            }
        }

        return write;
    }
};