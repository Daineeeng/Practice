#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int answer = 0;
    for(int i=1; i<=n; i++){
        float nmg =  n % i;
        if(nmg==0.0) {
            answer+=i;
        }
    }        
    return answer;
}
