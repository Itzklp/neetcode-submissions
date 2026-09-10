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
        ListNode* curr = head;

        vector<ListNode*> list;

        while (curr != nullptr) {
            list.push_back(curr);
            curr = curr->next;
        }

        int i = 0, j = list.size() - 1;

        while (i < j) {
            list[i]->next = list[j];
            i++;

            if (1 == j) {
                break;
            }

            list[j]->next = list[i];
            j--;
        }

        list[i]->next = nullptr;
    }
};
