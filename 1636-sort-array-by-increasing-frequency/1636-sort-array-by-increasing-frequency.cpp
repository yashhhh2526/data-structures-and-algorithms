class Solution {
public:
    static bool cmp(pair<int,int> a, pair<int,int> b) {
        if (a.second == b.second)
            return a.first > b.first;
        return a.second < b.second;
    }

    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> mp;

        for (int x : nums)
            mp[x]++;

        vector<pair<int,int>> temp;

        for (auto &it : mp)
            temp.push_back({it.first, it.second});

        sort(temp.begin(), temp.end(), cmp);

        vector<int> res;

        for (auto &it : temp) {
            for (int i = 0; i < it.second; i++)
                res.push_back(it.first);
        }

        return res;
    }
};