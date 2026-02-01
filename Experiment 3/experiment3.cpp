// 24BCS13055

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<char> attendanceWindowVector(N);
    for (int i = 0; i < N; i++) {
        cin >> attendanceWindowVector[i];
    }

    unordered_map<int, int> mp; 
    
    mp[0] = -1;

    int currentSum = 0;
    int maxLength = 0;


    for (int i = 0; i < N; i++) {
        if (attendanceWindowVector[i] == 'P') {
            currentSum += 1;
        } else {
            currentSum -= 1;
        }


        if (mp.find(currentSum) != mp.end()) {
            int windowLength = i - mp[currentSum];
            maxLength = max(maxLength, windowLength);
        } else {
            mp[currentSum] = i;
        }
    }

    cout << maxLength << endl; 

    return 0;
}
