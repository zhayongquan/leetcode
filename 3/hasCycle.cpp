#include<iostream>
#include<unordered_set>
#include<set>

using namespace std;

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*>seen;
        while(head != nullptr){
            if(seen.count(head))
                return true;
            seen.insert(head);
            head = head->next;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    ListNode fir(1);
    ListNode* bug = &fir;
    bool ret = sol.hasCycle(bug);
    cout<<"ret: "<<ret<<endl;
    return 0;
}