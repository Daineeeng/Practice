#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long solution(int a, int b) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long answer = 0;
    if(a == b) {
         answer = a;       
    } else if (a < b) {
        for(int i=a; i<=b; i++) {
            answer += i;
        }
    } else {
        for(int i=b; i<=a; i++) {
            answer += i;
        }
    }
    return answer;
}
