class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* temp=head;
        head=head->next;
        temp->next=NULL;
        while(head){
            ListNode* curr=head->next;
            head->next=temp;
            temp=head;
            head=curr;
        }
        return temp;
    }
};