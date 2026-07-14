// TODO: Finish this.. thing.    
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
        // Expects the pointer before the duplicate group
        // returns the address of the next element outside of the group.
        // e.g. 1 2 3 3 4, input 1, retuns address of 4.
        ListNode* removeGroup(ListNode* head) {
          ListNode* current = head;
          int duplicate = head->val;
          while (current->next != nullptr) {
            if (current->val == duplicate) {
              current = current->next;
            } else 
              break;
            }
          }
          head->next = current->next;
          return head;
        }

        ListNode* deleteDuplicates(ListNode* head) {
          ListNode* newHead = head;
          ListNode* current = head;
          ListNode* PrevUnique = head;

          while (current != nullptr) {
            current = current->next;
            if (current->val == PrevUnique->val) {
              current = removeGroup(PrevUnique);
            }
          }
        }
    };

