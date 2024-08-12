#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* oddEvenList(ListNode* head) {
    if (!head || !head->next)
        return head;

    ListNode* oddHead = new ListNode(0);
    ListNode* evenHead = new ListNode(0);
    ListNode* odd = oddHead;
    ListNode* even = evenHead;

    bool isOdd = true;
    while (head) {
        if (isOdd) {
            odd->next = head;
            odd = odd->next;
        } else {
            even->next = head;
            even = even->next;
        }
        isOdd = !isOdd;
        head = head->next;
    }

    odd->next = evenHead->next;
    even->next = nullptr;

    return oddHead->next;
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    // Example usage
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* result = oddEvenList(head);
    printList(result);

    // Clean up memory (not necessary in practice)
    while (result) {
        ListNode* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}
