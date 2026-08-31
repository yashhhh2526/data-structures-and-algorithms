class Solution {
public:
    int minimumPushes(string word) {
        map<char, int> mp;
        for(char c : word) {
            mp[c]++;
        }

        vector<int> freq;

        for(auto it : mp) {
            freq.push_back(it.second);
        }
        sort(freq.rbegin(), freq.rend());

        int cost = 0;

        for(int i = 0; i < freq.size(); i++) {
            int pushes = (i / 8) + 1;
            cost += freq[i] * pushes;
        }

        return cost;
    }
};