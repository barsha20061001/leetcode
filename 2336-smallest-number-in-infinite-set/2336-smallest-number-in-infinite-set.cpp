class SmallestInfiniteSet {
    int current;
    set<int> added;

public:
    SmallestInfiniteSet() {
        current = 1;
    }

    int popSmallest() {
        if (!added.empty()) {
            int x = *added.begin();
            added.erase(added.begin());
            return x;
        }
        return current++;
    }

    void addBack(int num) {
        if (num < current)
            added.insert(num);
    }
};
/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */