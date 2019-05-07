#include <iostream>
#include <string>
using namespace std;

bool solution(string s) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int chk = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(') chk++;
        else chk--;
        if(chk < 0) return false;
    }
    if(chk!=0) return false;
    return true;
}
