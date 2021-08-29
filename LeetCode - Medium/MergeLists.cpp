/*
* @Author: Patrick Manacorda 
* @Date: August 28th 2021
* Merge two sorted linked lists and return it as a sorted list. 
* The list should be made by splicing together the nodes of the first two lists.
*/

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* root, *head;
        if(l1 || l2){
            root = new ListNode();
            head = root;
        }else{
            return nullptr;
        }
        
        while(l1 && l2){
            if(l1->val < l2->val){
                root->val = l1->val;
                l1 = l1->next;
            }else{
                root->val = l2->val;
                l2 = l2->next;
            }
            if(l1 || l2){
                root->next = new ListNode();
                root = root->next;
            }
        }
        while(l1){
            root->val = l1->val;
            l1 = l1->next;
            
            if(l1){
                root->next = new ListNode();
                root = root->next;
            }
        }
        while(l2){
            root->val = l2->val;
            l2 = l2->next;
            
            if(l2){
                root->next = new ListNode();
                root = root->next;
            }
        }
        
        return head;
    }
};