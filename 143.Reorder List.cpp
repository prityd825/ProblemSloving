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
ListNode* reverse(ListNode* head)
{
    ListNode* pre = NULL;
    ListNode* cur= head;
    ListNode* nxt = NULL;

    while(cur)
    {
        nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }
    return pre;
}

void reorderList(ListNode* head)
{
    ListNode* slow = head;
    ListNode* fast = head -> next;

    while(fast and fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* second = reverse(slow->next);
    slow->next = NULL;
    ListNode* first = head;

    while(second){
        ListNode* temp1 = first->next;
        ListNode* temp2 = second->next;
        first->next = second;
        second->next = temp1;
        first = temp1;
        second= temp2;
    }
}

};
