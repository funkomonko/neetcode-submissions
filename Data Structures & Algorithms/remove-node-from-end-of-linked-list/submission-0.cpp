class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 1. Create a dummy node pointing to the head.
        // This guarantees our 'left' pointer always has a safe place to stand.
        ListNode* dummy = new ListNode(0, head);
        
        ListNode* left = dummy;
        ListNode* right = head;
        
        // 2. Give the 'right' pointer an 'n' step head start
        while (n > 0 && right != nullptr) {
            right = right->next;
            n--;
        }
        
        // 3. Move both pointers together. 
        // When 'right' hits the end, 'left' will be exactly ONE node before the target.
        while (right != nullptr) {
            left = left->next;
            right = right->next;
        }
        
        // 4. Delete the node by skipping over it
        ListNode* nodeToDelete = left->next;
        left->next = left->next->next;
        
        // 5. Memory cleanup (Highly recommended in C++ interviews!)
        delete nodeToDelete;
        ListNode* newHead = dummy->next;
        delete dummy; 
        
        return newHead;
    }
};