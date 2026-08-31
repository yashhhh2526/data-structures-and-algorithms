class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int, vector<int>> mp;
        int mini = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];

            mp[x].push_back(i);

            if (mp[x].size() >= 3) {
                int m = mp[x].size();

                int a = mp[x][m - 3];
                int b = mp[x][m - 2];
                int c = mp[x][m - 1];

                int diff = abs(a - b) + abs(b - c) + abs(a - c);
                mini = min(mini, diff);
            }
        }

        return mini == INT_MAX ? -1 : mini;
    }
};