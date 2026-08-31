class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            int a = nums[i];
            for(int j = i + 1 ; j < n ; j++){
                if(nums[j] == a){
                    for(int k = j + 1 ; k < n ; k++){
                        if(nums[k] == a){
                            int diff = abs(i - j) + abs(k-j) + abs(k-i);
                            mini = min(mini , diff);
                        }
                    }
                }
            }
        }
        if(mini == INT_MAX){
            return -1;
        }else{
            return mini;
        }
    }
};