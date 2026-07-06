class Solution {
private:
    vector<int> getPSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if (st.empty())
                pse[i] = -1;
            else
                pse[i] = st.top();

            st.push(i);
        }
        return pse;
    }

    vector<int> getNSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (st.empty())
                nse[i] = n;
            else
                nse[i] = st.top();

            st.push(i);
        }
        return nse;
    }

public:
    static const int MOD = 1e9 + 7;

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> pse = getPSE(arr);
        vector<int> nse = getNSE(arr);

        long long total = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;

            total = (total + 1LL * arr[i] * left * right) % MOD;
        }

        return total;
    }
};