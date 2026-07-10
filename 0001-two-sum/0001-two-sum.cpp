class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mpp;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            int sum = nums[i];
            int more = target-sum;
            if(mpp.find(more) != mpp.end()){
                return{mpp[more],i};
            }
            mpp[sum] = i;
        }
        return {-1,-1};
    }
};