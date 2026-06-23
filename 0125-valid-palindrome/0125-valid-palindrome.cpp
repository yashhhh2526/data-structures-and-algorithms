class Solution {
private:
    bool check(string &s, int i) {
        if (i >= s.length() / 2) {
            return true;
        }

        if (s[i] != s[s.length() - i - 1]) {
            return false;
        }

        return check(s, i + 1);
    }

public:
    bool isPalindrome(string s) {
        string res = "";

        for (char c : s) {
            if (!isalnum(c)) {
                continue;
            }
            res += tolower(c);
        }

        return check(res, 0);
    }
};