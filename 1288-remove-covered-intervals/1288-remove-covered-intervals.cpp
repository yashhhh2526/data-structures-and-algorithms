class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] == b[0])
                     return a[1] > b[1];   
                 return a[0] < b[0];       
             });

        int n = intervals.size();
        int end = intervals[0][1];
        int count = 0;

        for (int i = 1; i < n; i++) {
            int currEnd = intervals[i][1];

            if (currEnd <= end) {   
                count++;
            } else {
                end = currEnd;
            }
        }

        return n - count;
    }
};