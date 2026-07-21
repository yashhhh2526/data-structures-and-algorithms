class Solution {
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;   // Min heap
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        for (auto list : lists) {
            ListNode* curr = list;
            while (curr) {
                pq.push(curr);
                curr = curr->next;
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while (!pq.empty()) {
            temp->next = pq.top();
            temp = temp->next;
            pq.pop();
        }

        temp->next = nullptr;

        return dummy->next;
    }
};