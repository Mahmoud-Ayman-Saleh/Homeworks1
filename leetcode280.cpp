#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void recursiveArrange(const vector<int>& arr, vector<int>& ans, int left, int right) {
    if (left > right) return; // Base case: stop when left index exceeds right

    ans.push_back(arr[left]); // Add the smallest element
    if (left != right) {      // Avoid duplicating the middle element in odd-sized arrays
        ans.push_back(arr[right]); // Add the largest element
    }

    recursiveArrange(arr, ans, left + 1, right - 1); // Recursive call for the next elements
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end()); // Sort the array
    recursiveArrange(arr, ans, 0, n - 1); // Start the recursive process

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}
