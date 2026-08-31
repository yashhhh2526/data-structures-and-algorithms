class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<pair<ListNode*, int>> critical;

        int start = 1;
        ListNode* temp = head->next;
        ListNode* prev = head;

        if (temp->next == NULL) {
            return {-1, -1};
        }

        while (temp->next) {
            if ((temp->val < temp->next->val && temp->val < prev->val) ||
                (temp->val > temp->next->val && temp->val > prev->val)) {
                
                critical.push_back({temp, start});
            }

            start++;
            prev = temp;
            temp = temp->next;
        }

        if (critical.size() < 2) {
            return {-1, -1};
        }

        int minDiff = INT_MAX;

        for (int i = 1; i < critical.size(); i++) {
            int diff = critical[i].second - critical[i - 1].second;
            minDiff = min(minDiff, diff);
        }

        int maxDiff = critical.back().second - critical.front().second;

        return {minDiff, maxDiff};
    }
};