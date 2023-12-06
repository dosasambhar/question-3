#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 5, 1};
    int k = 3;

    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (arr[i] == arr[j] && abs(i - j) <= k) {
                cout << "Duplicate found at indices " << i << " and " << j << ": " << arr[i] << endl;
                return 0;  // Exit the program after finding the first duplicate within the specified range
            }
        }
    }

    cout << "No duplicates found within the specified range." << endl;
    return 0;
}

