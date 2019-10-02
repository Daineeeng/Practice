#include <iostream>
#include <string>
#include <vector>
using namespace std;

double solution(vector<int> arr) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    double sum = 0.0;
    int arr_sz = arr.size();
    for(int i=0; i<arr_sz; i++) {
        sum += arr[i];
    }
    double answer = sum / arr_sz;
    return answer;
}
