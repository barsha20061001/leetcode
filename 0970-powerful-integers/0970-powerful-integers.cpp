class Solution {
public:
vector<int> powerfulIntegers(int x, int y, int bound) {
unordered_set<int> st;
 for (long long a = 1; a <= bound; a *= x) {
for (long long b = 1; a + b <= bound; b *= y) {
st.insert(a + b);
if (y == 1) break; }
 if (x == 1) break;}
return vector<int>(st.begin(), st.end()); }
};