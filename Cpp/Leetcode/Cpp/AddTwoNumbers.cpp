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
    void carryTens(ListNode* l1) {
      while (true) {
        if (l1->val >= 10) {
          l1->val %= 10;
          if (l1->next != nullptr) {
            l1->next->val += 1;
            l1 = l1->next;
          } else {
            l1->next = new ListNode(1);
            break;
          }
        } else {
          break;
        }
      }
    }  

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;
        ListNode* prevl1 = l1;
        while (true) {
            if (l1 != nullptr && l2 != nullptr) {
              l1->val = l1->val + l2->val;
              carryTens(l1);
            }
            else if (l1 == nullptr && l2 != nullptr) { prevl1->next = l2; break; }
            else if (l1 != nullptr && l2 == nullptr) { break; }
            else if (l1 == nullptr && l2 == nullptr) { break; }
            prevl1 = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        return head;
    }
};
