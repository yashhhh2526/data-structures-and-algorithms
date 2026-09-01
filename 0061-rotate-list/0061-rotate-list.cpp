class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;

        int n = 1;
        ListNode* tail = head;

        while (tail->next) {
            n++;
            tail = tail->next;
        }

        k %= n;
        if (k == 0)
            return head;

        int steps = n - k - 1;
        ListNode* curr = head;

        while (steps--) {
            curr = curr->next;
        }

        ListNode* newHead = curr->next;
        curr->next = NULL;
        tail->next = head;

        return newHead;
    }
};