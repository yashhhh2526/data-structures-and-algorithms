class Solution {
public:
    int trap(vector<int>& height) {
        int lmax = 0,rmax = 0,total = 0;
        int l = 0;
        int r = height.size() -1;
        while(l<r){
            if(height[l] <= height[r]){
                if(height[l] < lmax){
                    total = total + lmax-height[l];
                }else{
                    lmax = height[l];
                }
                l++;
            }else{
                if(height[r] < rmax){
                    total = total + rmax - height[r];
                }else{
                    rmax = height[r];
                }
                r--;
            }
        }
        return total;
    }
};