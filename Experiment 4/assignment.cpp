#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int K, N;
    
    cout << "Enter K: ";
    cin >> K;
    cout << "Enter N: ";
    cin >> N;

    // using min heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    cout << "Enter scores:" << endl;
    for (int i = 0; i < N; i++) {
        int score;
        cin >> score;

        if (minHeap.size() < K) {
            minHeap.push(score);
        } else {
            // compare with smallest element in heap
            if (score > minHeap.top()) {
                minHeap.pop();
                minHeap.push(score);
            }
        }

        if (minHeap.size() < K) {
            cout << "-1" << endl;
        } else {
            cout << minHeap.top() << endl;
        }
    }

    return 0;
}
