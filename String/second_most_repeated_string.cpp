#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    string secFrequent (string arr[], int n)
    {
        unordered_map<string, int> mpp;
        for (int i = 0; i < n; ++i) {
            if(mpp.find(arr[i])!=mpp.end()){
                mpp[arr[i]]++;
            }else{
                mpp[arr[i]] = 1;
            }
        }

        int first_max = INT_MIN, second_max = INT_MIN;
        string key;
        int value = 0;
        for(auto & entry : mpp){
            key = entry.first;
            value = entry.second;

            if(value > first_max){
                second_max = first_max;
                first_max = value;
            }else if(value > second_max && value < first_max){
                second_max = value;
            }
        }

        for(auto & entry : mpp){
            if(entry.second == second_max){
                return entry.first;
            }
        }
        return nullptr;
    }
};
int main()
{

    return 0;
}