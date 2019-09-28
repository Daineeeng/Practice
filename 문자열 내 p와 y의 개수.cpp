#include <iostream>
#include <string>
using namespace std;

bool solution(string s) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    bool answer = false;
    int ans = -1;
    for(int i=0; i<s.length(); i++) {
        if(s[i]=='p' || s[i]=='P') ans++;
        else if (s[i]== 'y' || s[i]=='Y') ans--;
    }
    if(ans == -1) answer=true;
    return answer;
}
