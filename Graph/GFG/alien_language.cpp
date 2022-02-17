#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    unordered_map<char,vector<char>> graph;
    string findOrder(string dict[], int N, int K) {
        int n = N;
        vector<int> inDegree(K,0);
        for(int i = 0; i < n-1 ; i++){
            string word1 = dict[i], word2 = dict[i+1];
            for(int j = 0; j < min(word1.size(),word2.size()); j++){
                if(word1[j] != word2[j]){
                    graph[word1[j]].push_back(word2[j]);
                    inDegree[word2[j]-'a']++;
                    break;
                }
            }
        }
        
        queue<char> q;
        vector<bool> visited(K,false);
        string ans = "";
        for(int i = 0; i < K; i++){
            if(inDegree[i] == 0){
                q.push((char)(i+'a'));
                visited[i] = true;
                ans += ((char)(i+'a'));
            }
        }
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            for(auto nodes: graph[node]){
                if(visited[nodes-'a'] == false){
                    if(--inDegree[nodes-'a'] == 0){
                        ans += (char)(nodes);
                        q.push(nodes);
                        visited[nodes-'a'] = true;
                    }
                }
            }
        }
        return ans;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
