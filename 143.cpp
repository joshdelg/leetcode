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
    void reorderList(ListNode* head) {
        // NeetCode Solution

        // NEW TECHNIQUE: Find middle using slow, fast pointer!
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        slow->next = nullptr;

        while(curr != nullptr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        // Connect head->tail and tail->nextHead and increment
        ListNode* currHead = head;
        ListNode* currTail = prev;

        while(currTail != nullptr) {
            ListNode* tempHead = currHead->next;
            ListNode* tempTail = currTail->next;

            currHead->next = currTail;
            currHead = tempHead;

            currTail->next = currHead;
            currTail = tempTail;
        }

        // // My approach (Accepted, O(n))
        
        // // Compute length of list
        // int listLen = 0;
        // ListNode* curr = head;
        
        // while(curr != nullptr) {
        //     curr = curr->next;
        //     listLen++;
        // }

        // // Reverse second half of the list
        // ListNode* originalHead = head;
        // ListNode* currTail = head;

        // ListNode* prev = nullptr;
        // curr = originalHead;

        // int index = 0;
        // while(curr != nullptr) {
        //     if(index == listLen / 2) {
        //         ListNode* temp = curr->next;
        //         curr->next = nullptr;
        //         prev = curr;
        //         curr = temp;
        //     } else if(index > listLen / 2) {
        //         ListNode* temp = curr->next;
        //         curr->next = prev;
        //         prev = curr;
        //         curr = temp;
        //     } else {
        //         prev = curr;
        //         curr = curr->next;
        //     }

        //     index++;
        // }

        // ListNode* currHead = originalHead;
        // currTail = prev;

        // // Order head->tail, tail->head, etc until they meet
        // int it = 0;
        // while(currHead != currTail) {
        //     if(it % 2 == 0) {
        //         ListNode* temp = currHead->next;
        //         currHead->next = currTail;
        //         currHead = temp;
        //     } else {
        //         ListNode* temp = currTail->next;
        //         currTail->next = currHead;
        //         currTail = temp;
        //     }

        //     it++;
        // }
    }
};