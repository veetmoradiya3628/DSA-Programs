#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 1000
class MyStack{
private:
    int top;
    int arr[MAX_SIZE];
public:
    MyStack(){
        top = -1;
    }
    bool push(int x);
    bool isEmpty();
    int pop();
    int peek();
};
bool MyStack::push(int x) {
    if(top >= (MAX_SIZE - 1)){
        cout<<"Stack overflow"<<endl;
        return false;
    }else{
        arr[++top] = x;
        cout<<x<<" pushed into stack"<<endl;
        return true;
    }
}

int MyStack::pop() {
    if(top < 0)
    {
        cout<<"Stack Underflow"<<endl;
        return 0;
    }else{
        int x = arr[top--];
        return x;
    }
}
int MyStack::peek() {
    if(top < 0)
    {
        cout<<"Stack is Empty"<<endl;
        return 0;
    }else{
        int x = arr[top];
        return x;
    }
}
bool MyStack::isEmpty() {
    return (top < 0);
}
int main()
{
    MyStack stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    cout<<stk.peek()<<endl;
    stk.pop();
    cout<<stk.isEmpty()<<endl;
    cout<<stk.peek()<<endl;
    stk.pop();
    stk.pop();
    stk.pop();
    cout<<stk.isEmpty()<<endl;
    return 0;
}