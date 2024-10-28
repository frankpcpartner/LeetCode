//Runtime: 1 ms, 6.58%
//Memory: 19.86 MB, 17.46% 

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
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
{
    ListNode dummy;
    ListNode* ret = &dummy;

    while (list1 || list2)
    {
        int val = 0;

        if (list1 != NULL && list2 != NULL)
        {
            if (list1->val < list2->val)
            {
                val = list1->val;
                list1 = list1->next;
            }
            else
            {
                val = list2->val;
                list2 = list2->next;
            }
        }
        else if (list1 != NULL)
        {
            val = list1->val;
            list1 = list1->next;
        }
        else
        {
            val = list2->val;
            list2 = list2->next;
        }

        ret->next = new ListNode(val);
        ret = ret->next;
    }

    return dummy.next;
}
};
