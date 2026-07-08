class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int> mpp;
        for(auto num : arr){
            mpp[num]++;
        }
        vector<int> res;
        for(auto& it : mpp){
            if(it.first == it.second){
                res.push_back(it.first);
            }
        }
        if(res.empty()){
            return -1;
        }else{
            return res.back();
        }
    }
};