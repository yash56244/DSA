/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head){
            return head;
        }
        ListNode* temp = head;
        ListNode* newl = new ListNode(head->val);
        ListNode* tempn = newl;
        int prev;
        while(temp!= NULL){
            if(temp == head){
                prev = temp->val;
            }
            else{
                if(prev != temp->val){
                    newl->next=temp;
                    newl = newl->next;
                    prev=temp->val;
                }
            }
            temp=temp->next;
        }
        newl->next = NULL;
        return tempn;
    }
};
