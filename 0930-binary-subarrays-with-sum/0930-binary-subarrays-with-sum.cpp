class Solution {
    private:
    int prefixSum(vector<int>& nums,int goal){
        if(goal<0){
            return 0;
        }
        int l = 0;
        int r = 0;
        int cnt = 0;
        int sum = 0;
        while(r<nums.size()){
            sum = sum + nums[r];
            while(sum>goal){
                sum = sum - nums[l];
                l++;
            }
            cnt = cnt + (r-l+1);
            r++;
        }
        return cnt;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       return prefixSum(nums,goal) - prefixSum(nums,goal - 1);
    }
};