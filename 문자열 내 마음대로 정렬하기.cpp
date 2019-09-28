#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
bool sorting(string s1, string s2) {
    if(s1[N] == s2[N]){
        return s1 < s2;
    } else {
        return s1[N] < s2[N];
    }
}

vector<string> solution(vector<string> strings, int n) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    N = n;
    sort(strings.begin(), strings.end(), sorting);
    vector<string> answer;
    answer = strings;
    return answer;
}
