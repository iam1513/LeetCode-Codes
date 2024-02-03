class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // Step 1: Check if the linked list is empty or has only one node
        if (!head || !head->next) {
            return head;
        }

        // Step 2: Find Length of the Linked List
        ListNode* tail = head;
        int size = 0;
        while (tail->next) {
            size++;
            tail = tail->next;
        }
        size++; // For including the last node

        // Step 3:  Find by how many steps we have to rotate
        k = k % size;

        if (k == 0) {
            return head;
        }

        tail->next = head;

        // Step 4: Traverse size-k nodes
        ListNode* temp = head;
        for (int i = 1; i < size - k; i++) {
            temp = temp->next;
        }

        // Step 5: Temp is pointing to (size-k)th node
        ListNode* newhead = temp->next;
        temp->next = nullptr;
        return newhead;
    }
};
