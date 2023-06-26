class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if (headA == NULL || headB == NULL) return NULL;

        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;

        while(ptr1 != ptr2){

           ptr1 == NULL ? ptr1 =  headB : ptr1 =  ptr1 -> next;
           ptr2 == NULL ? ptr2 =  headA : ptr2 = ptr2 -> next;
        }

        return ptr2;

    }
        
};
