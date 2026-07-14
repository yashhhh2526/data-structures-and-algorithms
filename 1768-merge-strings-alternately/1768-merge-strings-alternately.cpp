class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        int i = 0, j = 0;
        string res;
        while(i<n1 && j  < n2){
            res = res + word1[i];
            res = res + word2[j];
            i++;
            j++;
        }
        while(i<n1){
            res = res + word1[i];
            i++;
        }
        while(j<n2){
            res = res + word2[j];
            j++;
        }
        return res;
    }
};