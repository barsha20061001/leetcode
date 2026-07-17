class Solution {
public:
    bool isValidSerialization(string preorder) {
        int slots = 1;
        string token;

        for (int i = 0; i <= preorder.size(); i++) {
            if (i == preorder.size() || preorder[i] == ',') {
                slots--;
                if (slots < 0) return false;

                if (token != "#")
                    slots += 2;

                token.clear();
            } else {
                token += preorder[i];
            }
        }

        return slots == 0;
    }
};