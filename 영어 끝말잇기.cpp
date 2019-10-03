#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);
    set<string> wordset;
    wordset.insert(words[0]);
    
    for(int i=1; i<(int)words.size(); i++) {
        if(wordset.find(words[i]) != wordset.end() ||  words[i-1].back() != words[i][0]) {
            answer[0] = (i%n) + 1; 
            answer[1] = (i/n) + 1;
            break;
        } else {
            wordset.insert(words[i]);
        }
    }
    return answer;
}
