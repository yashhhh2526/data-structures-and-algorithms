class Solution {
    private:
    void solve(vector<int>& nums,vector<vector<int>>& res,vector<int>& curr,int i,int n){
        if(i == n){
            res.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        solve(nums,res,curr,i+1,n);
        curr.pop_back();
        solve(nums,res,curr,i+1,n);
    }
public:	
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        int n = nums.size();
        solve(nums,res,curr,0,n);
        sort(res.begin(),res.end());
        return res;
    }
};