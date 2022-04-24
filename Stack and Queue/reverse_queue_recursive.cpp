#include<bits/stdc++.h>
using namespace std;
void reverse(queue<int> &q){
   if(q.size() > 1){
       int x = q.front();
       q.pop();
       reverse(q);
       q.push(x);
   }
}
//Function to reverse the queue.
queue<int> rev(queue<int> q)
{
    // add code here.
       reverse(q);
   return (q);
}