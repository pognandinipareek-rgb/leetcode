#ifndef LISTNODE_H
#define LISTNODE_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

#endif // LISTNODE_H

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return nullptr; // If the list is empty, return null.
        
        ListNode* sorted = new ListNode(0); // Dummy node to help with insertion.
        
        ListNode* current = head; // Pointer to traverse the original list.
        
        while (current) {
            ListNode* next = current->next; // Store the next node.
            ListNode* prev = sorted; // Start from the dummy node.
            
            // Find the position to insert the current node.
            while (prev->next && prev->next->val < current->val) {
                prev = prev->next;
            }
            
            // Insert the current node in the sorted list.
            current->next = prev->next;
            prev->next = current;
            
            // Move to the next node in the original list.
            current = next;
        }
        
        return sorted->next; // Return the sorted list, skipping the dummy node.
    }
};
