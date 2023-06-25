class Solution {
public:

    int countNodes(ListNode* head){

        int count = 0;

        ListNode* curr = head;

        while(curr != NULL){

            count++;
            curr = curr -> next;
        }

        return count;
    }

    ListNode* deleteNode(ListNode* head , int pos){

        ListNode* curr = head;

        if(pos == 0){

            head = head -> next;
        } 
            

        else {
            
             while(pos != 1 && curr != NULL){
    
            curr = curr -> next;
            
            pos--;
        }

        curr -> next = curr -> next -> next;
        }

        return head;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head == NULL ) return head;

        if(head -> next == NULL && n == 1) return NULL;

        int length = countNodes(head);
        
        int delNodePos = abs(length - n);

         return deleteNode(head , delNodePos);
   
    }
};
