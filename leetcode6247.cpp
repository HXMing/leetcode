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

#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeNodes(ListNode *head) {
  stack<ListNode *> stk;
  ListNode *p = head;
  while (p != nullptr) {
    while (!stk.empty() && stk.top()->val < p->val) {
      delete stk.top();
      stk.pop();
    }
    stk.push(p);
    p = p->next;
  }
  p = nullptr;
  while (!stk.empty()) {
    stk.top()->next = p;
    p = stk.top();
    stk.pop();
  }
  return p;
}
