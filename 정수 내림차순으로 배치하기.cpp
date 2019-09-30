#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long answer = 0;
    string str = to_string(n);
    sort(str.rbegin(), str.rend());
    answer = stoll(str);
    return answer;
}
