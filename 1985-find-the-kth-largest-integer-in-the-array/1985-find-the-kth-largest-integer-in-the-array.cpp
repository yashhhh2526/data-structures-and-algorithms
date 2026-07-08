class Solution {
public:
    struct cmp {
        bool operator()(string &a, string &b) {
            if (a.size() == b.size())
                return a > b;      // lexicographically larger
            return a.size() > b.size(); // longer string is larger
        }
    };

    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, cmp> pq;

        for (string &s : nums) {
            pq.push(s);

            if (pq.size() > k)
                pq.pop();
        }

        return pq.top();
    }
};