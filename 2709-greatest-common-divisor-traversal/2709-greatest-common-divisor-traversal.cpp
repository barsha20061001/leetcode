class Solution {
    class DSU {
        vector<int> parent, size;

    public:
        DSU(int n) {
            parent.resize(n);
            size.assign(n, 1);
            iota(parent.begin(), parent.end(), 0);
        }

        int find(int x) {
            if (parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        }

        void unite(int a, int b) {
            a = find(a);
            b = find(b);

            if (a == b) return;

            if (size[a] < size[b]) swap(a, b);

            parent[b] = a;
            size[a] += size[b];
        }
    };

public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return true;

        for (int num : nums) {
            if (num == 1) return false;
        }

        int maxValue = *max_element(nums.begin(), nums.end());

        vector<int> smallestPrimeFactor(maxValue + 1);

        for (int i = 2; i <= maxValue; i++) {
            if (smallestPrimeFactor[i] == 0) {
                for (int multiple = i; multiple <= maxValue; multiple += i) {
                    if (smallestPrimeFactor[multiple] == 0) {
                        smallestPrimeFactor[multiple] = i;
                    }
                }
            }
        }

        DSU dsu(n);
        unordered_map<int, int> primeOwner;

        for (int i = 0; i < n; i++) {
            int value = nums[i];

            while (value > 1) {
                int prime = smallestPrimeFactor[value];

                if (primeOwner.count(prime)) {
                    dsu.unite(i, primeOwner[prime]);
                } else {
                    primeOwner[prime] = i;
                }

                while (value % prime == 0) {
                    value /= prime;
                }
            }
        }

        int root = dsu.find(0);

        for (int i = 1; i < n; i++) {
            if (dsu.find(i) != root) {
                return false;
            }
        }

        return true;
    }
};