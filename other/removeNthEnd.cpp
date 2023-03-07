#include<iostream>
#include<string>
#include<stack>

using namespace std;

 // Definition for singly-linked list.
  struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0,head);
        ListNode* cur = dummy;
        stack<ListNode*> stk;
        while(cur)
        {
            stk.push(cur);
            cur = cur->next;
        }

        for(int i = 0; i < n; i++)
        {
            stk.pop();
        }
        ListNode* prev = stk.top();
        prev->next = prev->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};

int main()
{
    Solution sol;
    ListNode l5(5);
    ListNode l4(4,&l5);
    ListNode l3(3,&l4);
    ListNode l2(2,&l3);
    ListNode l1(1,&l2);

    ListNode* pri = sol.removeNthFromEnd(&l1,2);
    while (pri)
    {
        cout<<"val:"<<pri->val<<" ";
        pri = pri->next;
    }
    cout<<endl;


    return 0;
}