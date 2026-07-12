class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        
        for (int i = 0; i < (1 << n); i++) {
            ans.push_back(i ^ (i >> 1));
        }
        
        return ans;
    }
};

// The simplest and most efficient solution uses the Gray code formula:
//Gray(i)=i⊕(i>>1)
//Generate all numbers from 0 to (1<<n)-1 and convert each to its Gray code.