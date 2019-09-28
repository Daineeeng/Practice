#include<iostream>
#include <string>
#include <vector>
using namespace std;

string solution(int a, int b) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int month[]={31,29,31,30,31,30, 31,31,30,31,30,31};
    string date[] = {"FRI","SAT","SUN","MON","TUE","WED","THU"};
    int day = 0;
    for(int i=0; i<a-1; i++){
        day += month[i];
    }
    day = (day+b) % 7;
    day--;
    if(day < 0) day += 7;
    string answer = "";
    answer = date[day];
    return answer;
}
