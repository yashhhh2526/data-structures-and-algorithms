class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int num : asteroids) {
            bool destroyed = false;
            while (!st.empty() && st.top() > 0 && num < 0) {
                if (st.top() < -num) {
                    st.pop();                // stack asteroid destroyed
                }
                else if (st.top() == -num) {
                    st.pop();                // both destroyed
                    destroyed = true;
                    break;
                }
                else {
                    destroyed = true;        // current asteroid destroyed
                    break;
                }
            }
            if (!destroyed)
                st.push(num);
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};