class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mx = *max_element(nums.begin(),nums.end());
        int mn = *min_element(nums.begin(),nums.end());
        int sz = mx - mn + 1;
        vector<int>vis(mx+1,0);
        for(int num : nums){
            vis[num] = 1; 
        }
        vector<int>res;
        for(int i = mn;i<=mx;i++){
            if(vis[i] == 0){
                res.push_back(i);
            }
        }
        return res;
    }
};