class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL || head -> next == NULL || k <= 0) return head;

        //finding the last node.

        int length = 1;

        ListNode* lastNode = head;

        while( lastNode -> next != NULL){

            lastNode = lastNode -> next;

            length++;
        }

        lastNode -> next = head;

        int rotations = (k % length);

        int skip = (length - rotations);
        
        ListNode* newHead = head;

        while(skip > 1){
            
            newHead = newHead -> next;
            skip--;
        }
        

        head = newHead -> next;

        newHead -> next = NULL;

        return head;
        
    }
};
