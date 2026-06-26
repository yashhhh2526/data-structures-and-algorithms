class Fenwick {
    vector<long long> bit;
    int n;

public:
    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void update(int idx, int val) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }

    long long query(int idx) {
        long long res = 0;
        for (; idx > 0; idx -= idx & -idx)
            res += bit[idx];
        return res;
    }
};

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (nums[i] == target ? 1 : -1);
        }

        vector<long long> vals = pref;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        Fenwick ft(vals.size());

        long long ans = 0;

        for (long long p : pref) {
            int idx = lower_bound(vals.begin(), vals.end(), p) - vals.begin() + 1;

            // Count previous prefix sums strictly smaller than p
            ans += ft.query(idx - 1);

            ft.update(idx, 1);
        }

        return ans;
    }
};