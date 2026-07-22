class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i = 0 , j = 0 ;
        int n = g.size() , m = s.size();
        int cost = 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(i < n && j < m){
            if(g[i] <= s[j]){
                cost++;
                i++;
                j++;
            }else if(g[i] > s[j]){
                j++;
            }
        }
        return cost;
    }
};