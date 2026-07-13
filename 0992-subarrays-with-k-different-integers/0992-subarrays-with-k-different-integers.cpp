class Solution {
    private:
    int prefix(vector<int>& nums,int k){
        if(k<0){
            return 0;
        }
        unordered_map<int,int> mp;
        int l = 0;
        int ans = -1;
        for(int r = 0;r<nums.size();r++){
            mp[nums[r]]++;
            while(mp.size() > k){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            if(mp.size() <= k){
                ans = ans + (r-l+1);
            }
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return prefix(nums,k) - prefix(nums,k-1);
    }
};