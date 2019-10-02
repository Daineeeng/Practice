#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    string answer = "";
    for(int i=0; i<(int)participant.size(); i++) {
        if(participant[i] != completion[i]) {
            answer = participant[i];
            break;
        }
    }
    return answer;
}
