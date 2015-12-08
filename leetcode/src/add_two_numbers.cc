#include <iostream>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
using std::cout;
using std::endl;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    void show() {
        cout << val << endl;
        cout << next << endl;
        if (next) {
            next->show();
        }
    }
};

class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode *p1 = l1, *p2 = l2;
            ListNode *ans = new ListNode(0);
            ListNode *t = ans;
            int carry = 0;
            while (p1 && p2) {
                t->val = p1->val + p2->val + carry;
                carry = t->val/10;
                t->val = t->val%10;
                p1 = p1->next;
                p2 = p2->next;
                if (!p1 && !p2) {
                    t->next = NULL;
                    break;
                }
                if (!p1 || !p2) {
                    ListNode *tp=p1?p1:p2;
                    while (tp) {
                        t->next = new ListNode(0);
                        t = t->next;
                        t->val = carry + tp->val;
                        carry = t->val/10;
                        t->val = t->val%10;
                        tp = tp->next;
                    }

                    t->next = NULL;
                    break;
                }
                t->next = new ListNode(0);
                t = t->next;
            }
            if (carry) {
                t->next = new ListNode(0);
                t = t->next;
                t->val = carry;
            }
            return ans;
        }
};

int main()
{
    {
        ListNode *a, *b, *c;
        a = new ListNode(2);
        a->next = new ListNode(4);
        a->next->next = new ListNode(3);
        a->next->next->next = new ListNode(1);
        b = new ListNode(5);
        b->next = new ListNode(6);
        b->next->next = new ListNode(4);
        c = Solution().addTwoNumbers(a, b);
        c->show();
    }
    {
        ListNode *a, *b, *c;
        a = new ListNode(1);
        a->next = new ListNode(4);
        a->next->next = new ListNode(3);
        a->next->next->next = new ListNode(1);
        b = new ListNode(9);
        b->next = new ListNode(9);
        b->next->next = new ListNode(9);
        c = Solution().addTwoNumbers(a, b);
        c->show();
    }
}
