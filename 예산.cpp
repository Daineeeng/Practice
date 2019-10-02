#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> d, int budget) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sort(d.begin(), d.end());
    int answer = 0;
    for(int i=0; i<(int)d.size(); i++) {
        if(d[i] <= budget) {
            budget -= d[i];
            answer++;            
        } else break;
    }
    return answer;
}
