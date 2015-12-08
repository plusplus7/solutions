#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    void push(int x) {
        if (stk.empty()) {
            stk.push(0);
            now_min = x;
        } else {
            if (x >= now_min) {
                stk.push(x-now_min);
            } else {
                stk.push(x-now_min);
                now_min = x;
            }
        }
    }

    void pop() {
        if (stk.top() >= 0) {
            stk.pop();
        } else {
            now_min = now_min-stk.top();
            stk.pop();
        }
    }

    int top() {
        return now_min+stk.top();
    }
    int getMin() {
        return now_min;
    }
    class sidaike {
    public:
        struct Node {
            Node(long long x) : val(x), prev(NULL), next(NULL) {}
            long long val;
            Node *prev;
            Node *next;
        };
        Node* head;
        Node* tail;
        sidaike() : head(NULL), tail(NULL) {}
        bool empty() {
            return head == NULL;
        }
        
        void pop() {
            if (tail == NULL)
                return ;
            Node *tial = tail;
            tail = tail->prev;
            free(tial);
        }
        
        int top() {
            return empty()?0:tail->val;
        }

        void push(long long x) {
            if (head == NULL) {
                head = new Node(x);
                tail = head;
            } else {
                tail->next = new Node(x);
                tail->next->prev = tail;
                tail = tail->next;
            }
        }
    };
private:
    sidaike stk;
    int now_min;
};

int main() {
    MinStack ms;
    ms.push(1);
    cout<<ms.top()<<" "<<ms.getMin()<<endl;
    ms.push(2);
    cout<<ms.top()<<" "<<ms.getMin()<<endl;
    ms.push(3);
    cout<<ms.top()<<" "<<ms.getMin()<<endl;
    ms.push(-1);
    cout<<ms.top()<<" "<<ms.getMin()<<endl;
    ms.push(2);
    cout<<ms.top()<<" "<<ms.getMin()<<endl;
    ms.push(1);
    cout<<ms.top()<<" "<<ms.getMin()<<endl;

    return 0;
}
