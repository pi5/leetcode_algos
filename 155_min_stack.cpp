/*
   Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

   push(x) -- Push element x onto stack.
   pop() -- Removes the element on top of the stack.
   top() -- Get the top element.
   getMin() -- Retrieve the minimum element in the stack.

*/

#include<iostream>
#include<stack>
using namespace std;

/* We use two stacks. First stack stores the data it comes.
 * Second stack stores the current min value from first stack */
class MinStack {
    stack<int> s;
    stack<int> min;

    public:
    void push(int x) {
        if (min.empty() || min.top() >= x) {
            min.push(x);    
        }
        s.push(x); 
    }

    void pop() {
        if(!s.empty()) {
            if(s.top() == min.top()) {
                min.pop();    
            }
            s.pop();
        }
    }

    int top() {
        if(!s.empty()) {
            return s.top();   
        }
        return -1;
    }

    int getMin() {
        if(!min.empty()) {
            return min.top();   
        }
        return -1;
    }
};


int main() {
    MinStack s;
    s.push(1);
    s.push(2);
    cout << s.top();
    cout << s.getMin();
    s.pop();
    cout << s.getMin();
    cout << s.top();   
}
