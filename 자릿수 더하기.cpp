#include <iostream>

using namespace std;
int solution(int n)
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int answer = 0;
    while(n>0){
        answer += n%10;
        n /= 10;
    }
    return answer;
}
