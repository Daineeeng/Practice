#include <iostream>
#include <string>
#include <cmath>
using namespace std;

long long solution(long long n) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long x = sqrt(n);
    long long answer = -1;
    if(x*x == n) answer = (x+1)*(x+1);
    return answer;
}
