class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int pro = 1;
        int b = n;
        while(n){
            sum = sum + n%10;
            pro = pro*(n%10);
            n = n/10;
        }
        if(b%(sum + pro) == 0){
            return true;
        }else{
            return false;
        }
    }
};