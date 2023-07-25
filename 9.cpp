/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // NeetCode solution: Advance fast pointer first
        ListNode* fast = head;
        ListNode* slow = head;

        while(n > 0) {
            fast = fast->next;
            n--;
        }

        if(fast == nullptr) {
            return head->next;
        }

        while(fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return head;

        
        // My solution: Accepted
        // One pass: Start forward pointer, prev pointer n+1 nodes behind

        // ListNode* forward = head;
        // ListNode* prev = nullptr;

        // int listIndex = 0;
        // while(forward != nullptr) {
        //     cout << forward->val << listIndex << endl;
        //     if(listIndex == n + 1) {
        //         prev = head;
        //     }

        //     if(prev != nullptr) {
        //         prev = prev->next;
        //     }
            
        //     forward = forward->next;
        //     listIndex++;
        // }

        // if(prev == nullptr) {
        //     if(n == listIndex) {
        //         head = head->next;
        //     } else {
        //         prev = head;
        //         prev->next = prev->next->next;
        //     }
        // } else {
        //     prev->next = prev->next->next;
        // }

        // return head;

    }
};