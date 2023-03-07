#include<iostream>
#include<string>

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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head ->next == nullptr)
        {
            return head;
        }
        ListNode * newHead = head -> next;
        head->next = swapPairs(newHead->next);
        newHead ->next = head;
        return newHead;
    }
};

int main()
{
    ListNode * l1 = new ListNode(1);
    ListNode * l2 = new ListNode(2);
    ListNode * l3 = new ListNode(3);
    ListNode * l4 = new ListNode(4);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = nullptr;
    
    Solution sol;
    ListNode * p = sol.swapPairs(l1);
    cout<<"p: "<<p->val<<endl;
    return 0;
}