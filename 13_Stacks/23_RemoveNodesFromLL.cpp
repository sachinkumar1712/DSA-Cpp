
#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* fwd = curr->next;

            curr->next = prev;
            prev = curr;
            curr = fwd;
        }

        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        ListNode* temp = head;

        // Remove smaller nodes and push
        while (temp != nullptr) {
            while (!st.empty() && st.top()->val < temp->val) {
                st.pop();
            }

            st.push(temp);
            temp = temp->next;
        }

        // Reconstruct linked list in reverse order
        ListNode dummy(-1);
        temp = &dummy;

        while (!st.empty()) {
            ListNode* top = st.top();
            st.pop();

            temp->next = top;
            temp = top;
        }

        // Prevent cycles
        temp->next = nullptr;

        // Reverse to restore original order
        return reverse(dummy.next);
    }
};

int main() {
    ListNode* head = new ListNode(5);
    head->next = new ListNode(2);
    head->next->next = new ListNode(13);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(8);

    Solution obj;
    head = obj.removeNodes(head);

    ListNode* temp = head;

    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }

    cout << endl;

    return 0;
}
