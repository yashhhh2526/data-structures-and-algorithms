class Solution {
public:
    static const int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        int up[2005] = {0};
        int down[2005] = {0};
        int newUp[2005];
        int newDown[2005];
        int pref[2005];

        // Length = 2
        for (int v = 1; v <= m; v++) {
            up[v] = v - 1;
            down[v] = m - v;
        }

        for (int len = 3; len <= n; len++) {

            pref[0] = 0;
            for (int v = 1; v <= m; v++) {
                pref[v] = (pref[v - 1] + down[v]) % MOD;
            }

            for (int v = 1; v <= m; v++) {
                newUp[v] = pref[v - 1];
            }

            pref[0] = 0;
            for (int v = 1; v <= m; v++) {
                pref[v] = (pref[v - 1] + up[v]) % MOD;
            }

            int totalUp = pref[m];

            for (int v = 1; v <= m; v++) {
                newDown[v] = (totalUp - pref[v] + MOD) % MOD;
            }

            for (int v = 1; v <= m; v++) {
                up[v] = newUp[v];
                down[v] = newDown[v];
            }
        }

        long long ans = 0;

        if (n == 2) {
            for (int v = 1; v <= m; v++) {
                ans = (ans + up[v] + down[v]) % MOD;
            }
            return (int)ans;
        }

        for (int v = 1; v <= m; v++) {
            ans = (ans + up[v] + down[v]) % MOD;
        }

        return (int)ans;
    }
};