#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int minimumDays(int S, int N, int M){
        // code here
        int sun_day = S / 7;
        int y = S - sun_day;
        int sm = S * M;
        int days = sm / N;
        if(sm % N != 0) days++;
        if(days <= y) {
            return days;
        }else{
            return -1;
        }
    }
};
int main(){
    return 0;
}