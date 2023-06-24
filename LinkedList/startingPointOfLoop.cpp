class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        if(head == NULL || head -> next == NULL) return NULL;

        bool flag = false;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && slow != NULL){

            slow = slow -> next;

            if(fast -> next == NULL) return NULL;

            fast = fast -> next -> next;

            if(slow == fast){
                
                flag = true;
                
                break;
                
            }
        }

        if(flag == false) return NULL;

        fast = head;

        while(slow != fast) {

            slow = slow -> next;
            fast = fast -> next;
        }
           return slow;

     }   
};
