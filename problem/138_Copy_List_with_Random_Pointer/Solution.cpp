//Runtime: 2 ms, 92.02%
//Memory: 14.87 MB, 55.52% 

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
Node* copyRandomList(Node* head) 
{   
    Node dummy(0);
    Node* ret = &dummy;
    unordered_map<Node*, Node*> map;
    while (head)
    {
        ret->next = new Node(head->val);
        ret->next->random = head->random;

        map[head] = ret->next;
        ret = ret->next;
        head = head->next;
    }

    ret = dummy.next;
    while (ret)
    {
        if (ret->random != NULL)
        {
            ret->random = map[ret->random];
        }
        ret = ret->next;
    }

    return dummy.next;
}
};
