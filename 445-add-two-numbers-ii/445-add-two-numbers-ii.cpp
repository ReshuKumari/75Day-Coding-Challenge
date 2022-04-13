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
    ListNode* reverse(ListNode* l)
    {
        if(l==NULL || l->next==NULL)
            return l;
        ListNode* temp=reverse(l->next);
        l->next->next=l;
        l->next=NULL;
        return temp;
        
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverse(l1);
        l2=reverse(l2);
        ListNode dummy(-1);
        ListNode* tail=&dummy;
        ListNode *t1=l1, *t2=l2;
        int carry=0;
        while(t1 || t2)
        {
            int x=(t1==NULL)?0:t1->val;
            int y=(t2==NULL)?0:t2->val;
            int sum=x+y+carry;
            int d=sum%10;
            carry=sum/10;
            tail->next=new ListNode(d);
            tail=tail->next;
            if(t1!=NULL) t1=t1->next;
            if(t2!=NULL) t2=t2->next;
        }
        if(carry>0)
            tail->next=new ListNode(carry);
        return reverse(dummy.next);
    }
};