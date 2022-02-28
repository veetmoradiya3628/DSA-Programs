#include <bits/stdc++.h>
using namespace std;
class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
int pop();
};
void MyQueue :: push(int x)
{
    // Your Code
    arr[rear] = x;
    rear++;
}

//Function to pop an element from queue and return that element.
int MyQueue :: pop()
{
    if(rear==front)
        return -1;
    return arr[front++];
}

int main()
{

    return 0;
}