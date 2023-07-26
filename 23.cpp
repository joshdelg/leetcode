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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Naive: Iterate over each list, find min merge in O(k * (t)) = O(k^2*n)
        // Recursive: Recursively merge two lists until just one
        // WOOO POWER OF RECURSION FIRST HARDDD


        // Base case: No lists -> return
        if(lists.size() == 0) {
            return nullptr;
        }

        // Base case: One list left -> return
        if(lists.size() == 1) {
            return lists[0];
        }

        // If not, split lists in half and merge each
        int mid = lists.size() / 2;

        vector<ListNode*> lList = {};
        vector<ListNode*> rList = {};

        for(int i = 0; i < lists.size(); i++) {
            if(i < mid) {
                lList.push_back(lists[i]);
            } else {
                rList.push_back(lists[i]);
            }
        }

        ListNode* lMerged = mergeKLists(lList);
        ListNode* rMerged = mergeKLists(rList);

        // Merge both halves
        ListNode* result = nullptr;

        if(lMerged == nullptr) {
            return rMerged;
        } else if(rMerged == nullptr) {
            return lMerged;
        }

        if(lMerged->val < rMerged->val) {
            result = lMerged;
            lMerged = lMerged->next;
            result->next = nullptr;
        } else {
            result = rMerged;
            rMerged = rMerged->next;
            result->next = nullptr;
        }

        ListNode* tail = result;
        while(lMerged != nullptr && rMerged != nullptr) {
            if(lMerged->val < rMerged->val) {
                tail->next = lMerged;
                lMerged = lMerged->next;
                tail = tail->next;
            } else {
                tail->next = rMerged;
                rMerged = rMerged->next;
                tail = tail->next;
            }
        }

        if(lMerged != nullptr) {
            tail->next = lMerged;
        } else if(rMerged != nullptr) {
            tail->next = rMerged;
        } else {
            tail->next = nullptr;
        }

        // cout << "Printing Result" << endl;
        // ListNode* curr = result;
        // while(curr != nullptr) {
        //     cout << curr->val << "->";
        //     curr = curr->next;
        // }
        // cout << endl;

        return result;

    }
};