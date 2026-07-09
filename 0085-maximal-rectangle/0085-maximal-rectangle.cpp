class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> prevSmaller(n), nextSmaller(n);
        stack<int> st;

        // Previous Smaller Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            prevSmaller[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            nextSmaller[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            int width = nextSmaller[i] - prevSmaller[i] - 1;
            maxArea = max(maxArea, heights[i] * width);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> heights(cols, 0);
        int ans = 0;

        for (int i = 0; i < rows; i++) {
            // Build histogram (prefix heights)
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }

            // Find largest rectangle in current histogram
            ans = max(ans, largestRectangleArea(heights));
        }

        return ans;
    }
};