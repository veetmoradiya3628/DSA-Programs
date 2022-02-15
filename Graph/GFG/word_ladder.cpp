#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ladderLength(string start, string end, vector<string>& wordList) {
        queue<string> q;
        // adding first element into queue
        q.push(start);
        int wordSize = start.size();

        unordered_set<string> word;
        // adding all the words from wordList to word set
        for (auto & i : wordList) {
            word.insert(i);
        }

        // if word is not present in wordList
        if(word.find(end)==word.end()) return 0;

        int len = 0;
        while (!q.empty())
        {
            len++;
            int qlen = q.size();
            for (int i = 0; i < qlen; ++i) {
                // taking first element from queue
                string s = q.front();
                q.pop();

                // traverse over all over the word characters
                for (int j = 0; j < wordSize; ++j) {
                    // string original character
                    char original = s[j];

                    // replacing all possible character at all possible positions
                    for (char ch = 'a'; ch <= 'z'; ++ch) {

                        s[j] = ch;

                        // if we found the desired word then we can return the length as back
                        if(s==end)
                            return len + 1;

                        // if we do not found word in wordlist then we can continue
                        if(word.find(s)==word.end())
                            continue;

                        // removing next found word from wordList
                        word.erase(s);

                        // adding new string to the queue
                        q.push(s);
                    }
                    // replacing original character back
                    s[j] = original;
                }
            }
        }
    }
};
int main()
{
    vector<vector<int>> matrix;

    return 0;
}