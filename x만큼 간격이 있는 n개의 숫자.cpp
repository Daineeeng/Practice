#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<long long> solution(int x, int n) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<long long> answer;
    int plus = x;
    for(int i=0; i<n; i++) {
        answer.push_back(x);
        x += plus;
    }
    return answer;
}
