class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        for (ListNode* curr = head; curr; curr = curr->next) {
            n++;
        }
        
        int size = n / k;
        int extra = n % k;
        
        vector<ListNode*> res(k, nullptr);
        ListNode* curr = head;
        
        for (int i = 0; i < k && curr; ++i) {
            res[i] = curr;
            int part_size = size + (i < extra ? 1 : 0);
            
            for (int j = 1; j < part_size; ++j) {
                curr = curr->next;
            }
            
            ListNode* next_node = curr->next;
            curr->next = nullptr;
            curr = next_node;
        }
        
        return res;
    }
};