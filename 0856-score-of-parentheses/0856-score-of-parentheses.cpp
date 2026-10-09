
class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        int open = 0;
        int i = 0;

        while (i < s.size()) {
            if (s[i] == '(') {
                open++;
            } else {
                open--;
                if (s[i - 1] == '(') {
                    score += pow(2, open);
                }
            }
            i++;
        }

        return score;
    }
};