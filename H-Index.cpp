#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sort(citations.rbegin(), citations.rend());    
    int answer = 0;
    
    for(int i=0; i<citations.size(); i++) {
        if(citations[i] <= i) {
            answer = i;
            break;
        } else {
            answer = citations.size();
        }
    }
    return answer;
}
