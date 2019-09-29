#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solution(int n) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string answer = "";
    for(int i=0; i<n; i++){
        if(i%2==0) {
            answer += "수";
        } else {
            answer += "박";
        }
    }
    return answer;
}
