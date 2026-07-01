class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int noDelete = arr[0];
        int oneDelete = INT_MIN;
        int ans = arr[0];

        for (int i = 1; i < arr.size(); i++) {

            int prevNoDelete = noDelete;

            noDelete = max(arr[i], noDelete + arr[i]);

            if (oneDelete == INT_MIN)
                oneDelete = prevNoDelete;          
            else
                oneDelete = max(prevNoDelete, oneDelete + arr[i]);

            ans = max(ans, max(noDelete, oneDelete));
        }
        return ans;
    }
};