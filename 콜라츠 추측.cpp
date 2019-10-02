#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(int num) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int answer = 0;
    while(num != 1) {
        if(num%2==0) {
            num /= 2;
        } 
        else if (num%2==1) {
            num = (num*3) + 1;
        }
        answer++;

        if(answer == 500) {
            answer = -1;
            break;
        }
    }
    return answer;
}
