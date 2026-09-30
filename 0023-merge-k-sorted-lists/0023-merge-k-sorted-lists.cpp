class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;
        return mergeSub(lists, 0, lists.size() - 1);
    }

private:
    static ListNode* mergeSub(const vector<ListNode*>& lists, int left,
                              int right) {
        if (left == right)
            return lists[left];
        if (left + 1 == right)
            return merge(lists[left], lists[right]);
        int mid = left + (right - left) / 2;
        return merge(mergeSub(lists, left, mid),
                     mergeSub(lists, mid + 1, right));
    }

    static ListNode* merge(ListNode* a, ListNode* b) {
        if (a == nullptr)
            return b;
        if (b == nullptr)
            return a;
        ListNode* head;
        if (a->val <= b->val) {
            head = a;
            a = a->next;
        } else {
            head = b;
            b = b->next;
        }
        ListNode* curr = head;
        while (a && b) {
            if (a->val <= b->val) {
                curr->next = a;
                a = a->next;
            } else {
                curr->next = b;
                b = b->next;
            }
            curr = curr->next;
        }
        curr->next = a ? a : b;
        return head;
    }
};