class Solution {
public:
    int mirrorDistance(int n) {
        if(n <= 9) {
            return 0;
        }

        vector<int> rev;
        int b = n;

        while(b) {
            rev.push_back(b % 10);
            b = b / 10;
        }

        int reve = 0;

        for(int i = 0; i < rev.size(); i++) {
            reve = reve * 10 + rev[i];
        }

        return abs(reve - n);
    }
};