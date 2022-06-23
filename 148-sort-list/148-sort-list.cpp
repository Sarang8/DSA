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
    
    ListNode* mergeSort(ListNode* l1, ListNode* l2){
        
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        
        ListNode* temp = new ListNode (0);
        ListNode* curr=temp;
        
        while(l1!=NULL & l2!=NULL){
            
            if(l1->val <= l2->val){
                curr->next = l1;
                l1=l1->next;
            }
            else{
                curr->next = l2;
                l2=l2->next;
            }
            curr=curr->next;
        }
        
        if(l1!=NULL){
            curr->next = l1;
            l1=l1->next;
        }
        
        if(l2!=NULL){
            curr->next = l2;
            l2=l2->next;
        }
        
        return temp->next; 
    }
    
    
    
    
    ListNode* sortList(ListNode* head) {
        
        if(head==NULL or head->next==NULL){
            return head;
        }
        
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=head;
        
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast=fast->next->next;
        }
        
        prev->next=NULL;
        
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        
        return mergeSort(l1, l2);
         
        
    }
};