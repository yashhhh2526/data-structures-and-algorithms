class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int area = 0;
        int mx = INT_MIN;
        while(i<j){
            area = min(height[i],height[j])*(j-i);
            mx = max(area,mx);
            if(height[i]<height[j]){
                i++;
            }else{
                j--;
            }
        }
        return mx;
    }
};