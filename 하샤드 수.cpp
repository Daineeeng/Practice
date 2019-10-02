#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool solution(int x) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int y = 0;
    int temp = x;
    while(temp > 0) {
        y += (temp%10);
        temp /= 10;
    }
    bool answer = true;
    if(x % y != 0) answer = false;
    return answer;
}
