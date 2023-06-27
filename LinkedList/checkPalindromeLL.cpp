class Solution {

    ListNode* middleNode(ListNode* head){

        if(head == NULL || head -> next == NULL) return head;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast -> next != NULL){

            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }

    ListNode* reverseLinkedlist(ListNode* head){

        if(head == NULL || head -> next == NULL) return head;

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while(curr != NULL){

            next = curr -> next;

            curr -> next = prev;

            prev = curr;

            curr = next;
        }

        return prev;
    }

    bool checkPalindrome(ListNode* head1 , ListNode* head2){

        if(head1 == NULL || head2 == NULL) return true;

        ListNode* curr1 = head1;
        ListNode* curr2 = head2;

        while(curr1 != NULL && curr2 != NULL){

            if(curr1 -> val != curr2 -> val){

                return false; 
                break;
            }

            curr1 = curr1 -> next;
            curr2 = curr2 -> next;
        }

        return true;
    }
public:
    bool isPalindrome(ListNode* head) {

        ListNode* newHead = middleNode(head);

        ListNode* reverseHead = reverseLinkedlist(newHead);

        return checkPalindrome(head , reverseHead);
        
    }
};
