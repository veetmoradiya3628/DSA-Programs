#include<bits/stdc++.h>
using namespace std;
#define MAX 5
int q[MAX], front = -1, rear = -1;
void insert();
void _delete();
void display();
void insert(int x)
{
    if((front==0 && rear==MAX-1) || (rear + 1==front)){
        cout<<"Queue is overflow"<<endl;
    }else{
        if(rear==-1)
        {
            front = 0, rear = 0;
        }else if(rear == MAX - 1){
            rear = 0;
        }else{
            rear++;
        }
        q[rear] = x;
    }
}
void _delete()
{
    if(front==-1)
    {
        cout<<"Queue is Underflow"<<endl;
    }else{
        int val = q[front];
        if(front==rear)
            front = -1, rear = -1;
        else if(front==MAX-1)
            front = 0;
        else
            front++;
        cout<<"deleted element is : "<<val<<endl;
    }
}
void display()
{
    int i, j;
    if(front==-1 && rear == -1)
        cout<<"Queue is Underflow"<<endl;
    if(front > rear)
    {
        for (i = front;i < MAX; i++)
        {
            cout<<q[i]<<" ";
        }
        for (int j = 0; j <= rear; j++)
        {
            cout<<q[j]<<" ";
        }
    }else{
        for (int i = front; i <= rear; i++)
        {
            cout<<q[i]<<" ";
        }
    }
    cout<<endl;
}
int main()
{
    insert(1);
    insert(2);
    insert(3);
    display();
    insert(4);
    display();
    _delete();
    display();
    return 0;
}