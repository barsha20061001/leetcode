class CustomStack {
public:
    vector<int> st, inc;
    int maxSize;

    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }

    void push(int x) {
        if (st.size() == maxSize) return;
        st.push_back(x);
        inc.push_back(0);
    }

    int pop() {
        if (st.empty()) return -1;

        int i = st.size() - 1;
        int ans = st[i] + inc[i];

        if (i > 0)
            inc[i - 1] += inc[i];

        st.pop_back();
        inc.pop_back();

        return ans;
    }

    void increment(int k, int val) {
        if (st.empty()) return;

        int i = min(k, (int)st.size()) - 1;
        inc[i] += val;
    }
};
/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */