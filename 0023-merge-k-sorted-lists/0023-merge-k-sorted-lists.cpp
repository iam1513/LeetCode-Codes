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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {

        // NON REC

        if(head1 == NULL) return head2;
        
        if(head2 == NULL) return head1;

        ListNode* dummyHead = new ListNode(-1);
        ListNode* ptr1 = head1;
        ListNode* ptr2 = head2;
        ListNode* ptr3 = dummyHead;

    while(ptr1 && ptr2){//ptr1!=NULL && ptr2!NULL ===> Same as in bracket
        if(ptr1->val < ptr2->val){
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        else{
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }
    if(ptr1){
        ptr3->next = ptr1;
    }
    else{
        ptr3->next = ptr2;
    }

    return dummyHead->next;
    }
     
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return NULL;
        }

        while(lists.size() > 1){
            ListNode* mergeHead = mergeTwoLists(lists[0],lists[1]);
            lists.push_back(mergeHead); // pushing merged LL into the list
            lists.erase(lists.begin()); // Erasing two indices after merging em
            lists.erase(lists.begin());
        }

        return lists[0];
    }
};