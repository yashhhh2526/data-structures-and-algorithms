class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0;
        int xor_1 = start^goal;
        while(xor_1){
            if(xor_1&1){
                count++;
            }
            xor_1 = xor_1>>1;
        }
        return count;
    }
};