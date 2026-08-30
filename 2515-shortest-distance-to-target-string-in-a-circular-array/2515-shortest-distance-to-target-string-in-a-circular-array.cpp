class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int found = n;

        for(int i = 0; i < n; i++) {
            if(words[i] == target) {
                int clockwise = abs(i - startIndex);
                int circular = n - clockwise;

                found = min(found, min(clockwise, circular));
            }
        }

        return found == n ? -1 : found;
    }
};