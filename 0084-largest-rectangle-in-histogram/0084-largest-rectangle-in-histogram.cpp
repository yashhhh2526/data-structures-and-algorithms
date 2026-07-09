   class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> prevLess(n), nextLess(n);
        stack<int> st;

        // Previous Smaller
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            prevLess[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Smaller
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] > heights[i])
                st.pop();

            nextLess[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long mx = 0;

        for (int i = 0; i < n; i++) {
            long long width = nextLess[i] - prevLess[i] - 1;
            long long area = 1LL * heights[i] * width;
            mx = max(mx, area);
        }

        return mx;
    }
};