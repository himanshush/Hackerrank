#include <iostream>
using namespace std;
/**
 * Definition for singly-linked list.*/
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = NULL;
        ListNode* curr = NULL;
        ListNode* curr1=l1;
        ListNode* curr2=l2;
        int carry=0;
        while(curr1!=NULL ||curr2!=NULL)
        {
            int v=curr1->val+curr2->val+carry;
            if(v>=10)
            {
                v=v%10;
                carry=1;
            }
            else
                carry=0;
            ListNode* tmp=new ListNode(v);
            if(ans==NULL)
            {
                ans=tmp;
                curr=ans;
            }
            else
            {
                curr->next=tmp;
                curr=curr->next;
            }
            curr1=curr1->next;
            curr2=curr2->next;
        }
        return ans;
    }
};
int main()
{
    ListNode l1(3);
    ListNode l2(2);
    Solution s;
    ListNode* ans =s.addTwoNumbers(&l1,&l2);
    cout << ans->val;
}


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = NULL;
        ListNode* curr = NULL;
        ListNode* curr1=l1;
        ListNode* curr2=l2;
        int carry=0;
        while(curr1!=NULL ||curr2!=NULL)
        {
            //cout << "Hello" << endl;
            int v=curr1->val+curr2->val+carry;
            if(v>=10)
            {
                v=v%10;
                carry=1;
            }
            else
                carry=0;
            ListNode* tmp=new ListNode(v);
            if(ans==NULL)
            {
                ans=tmp;
                curr=ans;
            }
            else
            {
                curr->next=tmp;
                curr=curr->next;
            }
            curr1=curr1->next;
            curr2=curr2->next;
        }
        ListNode* node=NULL;
        if(curr1!= NULL)
            node=curr1;
        else if(curr2!=NULL)
            node=curr2;
        while(node!=NULL)
        {
            int v= node->val+carry;
            if(v>=10)
            {
                v=v%10;
                carry=1;
            }
            else
                carry=0;
            ListNode* tmp=new ListNode(v);
            if(ans==NULL)
            {
                ans=tmp;
                curr=ans;
            }
            else
            {
                curr->next=tmp;
                curr=curr->next;
                //cout << "hello" << endl;
            }
            node=node->next;
            //cout << "hello1" << endl;
        }
        if(carry==1)
        {
            ListNode* tmp=new ListNode(1);
            curr->next=tmp;
        }
        return ans;
    }
};
