class Solution {
public:
    ListNode* findKthNode(ListNode* temp, int k) {
        k--;

        while (temp && k > 0) {
            temp = temp->next;
            k--;
        }

        return temp;
    }

    ListNode* reverseLL(ListNode* head) {
        ListNode* prevNode = nullptr;
        ListNode* nextNode = nullptr;
        ListNode* temp = head;

        while (temp) {
            nextNode = temp->next;
            temp->next = prevNode;
            prevNode = temp;
            temp = nextNode;
        }

        return prevNode;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = nullptr;

        while (temp) {
            ListNode* kNode = findKthNode(temp, k);

            // Fewer than k nodes remain
            if (kNode == nullptr)
                break;

            ListNode* nextNode = kNode->next;

            // Disconnect current group
            kNode->next = nullptr;

            // Reverse current group
            reverseLL(temp);

            // Connect reversed group
            if (temp == head)
                head = kNode;
            else
                prevNode->next = kNode;

            // Connect to the next group
            temp->next = nextNode;

            // Move to next group
            prevNode = temp;
            temp = nextNode;
        }

        return head;
    }
};