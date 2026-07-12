class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp = arr;
        sort(temp.begin(),temp.end());
        unordered_map<int,int> mp;
        int rank = 0;
        for(int i = 0;i<n;i++){
            if(mp.find(temp[i]) == mp.end()){
                rank++;
                mp[temp[i]] = rank;
            }
        }
        vector<int> res;
        for(int i = 0;i<n;i++){
            res.push_back(mp[arr[i]]);
        }
        return res;
    }
};