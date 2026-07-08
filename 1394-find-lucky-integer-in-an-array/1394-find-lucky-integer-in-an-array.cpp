class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int> mpp;
        for(auto num : arr){
            mpp[num]++;
        }
        int mx = -1;
        for(auto& it : mpp){
            if(it.first == it.second){
                mx = max(mx,it.first);
            }
        }
        return mx;
    }
};