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
        // Step 1 : Check is LL have at least 3 nodes or not
        if(!head || !head->next || !head->next->next){
            return ;
        }

        // Step 2 : Finding Mid Node

        ListNode* slow = head;
        ListNode* fast = head;
       
        while(fast && fast->next){
            slow = slow->next;
            fast = fast -> next -> next;
        }

        // Step 3 : Separate List and reverse Second half
        ListNode* curr = slow->next;
        slow->next = NULL;
        ListNode* prev = slow;

        while(curr){
            ListNode* nextptr = curr -> next;
            curr->next = prev;
            prev = curr;
            curr = nextptr;
        }

        // Step 4 : Merge two lists
        ListNode* ptr1 = head;//LL first half
        ListNode* ptr2 = prev;//LL second half

        while(ptr1!=ptr2){
            ListNode* temp = ptr1->next;
            ptr1 -> next = ptr2;
            ptr1 = ptr2;
            ptr2 =temp;
        }

    }
};