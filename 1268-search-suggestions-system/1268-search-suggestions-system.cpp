class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products,
                                             string searchWord) {
        sort(products.begin(), products.end());

        vector<vector<string>> ans;
        string prefix;

        for (char ch : searchWord) {
            prefix += ch;

            auto it = lower_bound(products.begin(), products.end(), prefix);
            vector<string> suggestions;

            for (int i = 0; i < 3 && it + i != products.end(); i++) {
                string product = *(it + i);

                if (product.compare(0, prefix.size(), prefix) == 0)
                    suggestions.push_back(product);
                else
                    break;
            }

            ans.push_back(suggestions);
        }

        return ans;
    }
};