class Solution {
    private:
    void solve(vector<string>& ans , int open , int close , int n , string curr){
        if(curr.size() == 2*n){
            ans.push_back(curr);
            return;
        }

        if(open < n){
            solve(ans,open+1,close,n, curr + '(');
        }

        if(close < open){
            solve(ans,open,close+1,n, curr + ')');
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(ans,0,0,n,"");
        return ans;
    }
};