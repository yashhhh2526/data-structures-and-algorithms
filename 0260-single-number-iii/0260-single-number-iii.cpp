class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xor_1 = 0;
        for(auto num : nums){
            xor_1 = xor_1^num;
        }
        long long right_most = (xor_1&(xor_1 - 1))^xor_1;
        int b1 = 0,b2 = 0;
        for(auto num : nums){
            if(num&right_most){
                b1 = b1^num;
            }else{
                b2 = b2^num;
            }
        }
        return {b1,b2};
    }
};