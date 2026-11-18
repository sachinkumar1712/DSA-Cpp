class Solution {
  public:
    int getKthFromLast(Node* head, int k) {
        Node* slow = head;
        Node* fast = head;
        // Move fast k steps ahead
        for(int i=1;i<=k;i++){
            if(fast == NULL) return -1;
            fast = fast->next;
        }
        // Move slow and fast together until fast is not null
        while(fast != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        return slow->data;
    }
    // int getKthFromLast(Node* head, int k) {
    //     int len = 0;
    //     Node* temp = head;
    //     while(temp != NULL){
    //         temp = temp->next;
    //         len++;
    //     }
    //     temp = head;
    //     if(k > len) return -1;
    //     for(int i=1;i<=len-k;i++){
    //         temp = temp->next;
    //     }
    //     return temp->data;
    // }
};