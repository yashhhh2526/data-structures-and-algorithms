class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int sum = 0;
        map<int,int>mp;
        for(int num : nums){
            mp[num]++;
        }
        for(int num : nums){
            if(mp[num] == 1){
                sum = sum + num;
            }
        }
        return sum;
    }
};