//Runtime: 0 ms, 100.00%
//Memory: 77.54 MB, 41.76% 


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode dummy;
        ListNode* ret = &dummy;
        
        ListNode* l1Temp = l1;
        ListNode* l2Temp = l2;
        int toNext = 0;

        while(l1Temp != NULL || l2Temp != NULL)
        {
            int sum = 0;

            if(l1Temp != NULL){
                sum += l1Temp->val;
                l1Temp = l1Temp->next;                        
            }

            if(l2Temp != NULL){
                sum += l2Temp->val;
                l2Temp = l2Temp->next;
            }

            sum += toNext;
            toNext = sum / 10;
            sum = sum % 10;       

            ret->next = new ListNode(sum);
            ret = ret->next;
        }
        
        if(toNext)
        {
           ret->next = new ListNode(toNext);
        }

        return dummy.next;
    }
};
