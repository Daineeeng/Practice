#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(long long n) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> answer;
    while(n>0){
        answer.push_back(n%10);
        n /= 10;
    }
    return answer;
}
