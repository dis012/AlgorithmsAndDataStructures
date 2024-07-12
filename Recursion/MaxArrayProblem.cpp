#include <iostream>
#include <climits>

using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int find_max_cross_array(int *A, int l, int m, int h) {
    int left_sum = INT_MIN;
    int sum = 0; // Initialize sum to 0
    for (int i = m; i >= l; i--) {
        sum = sum + A[i];
        if (sum > left_sum) {
            left_sum = sum;
        }
    }

    int right_sum = INT_MIN;
    sum = 0;
    for (int j = m + 1; j <= h; j++) {
        sum = sum + A[j];
        if (sum > right_sum) {
            right_sum = sum;
        }
    }

    return max(left_sum + right_sum, max(left_sum, right_sum));
}

int find_max_subarray(int *A, int l, int h) {
    if (l == h) {
        return A[l];
    } else {
        int m = (l + h) / 2;
        int Lsum = find_max_subarray(A, l, m);
        int Rsum = find_max_subarray(A, m + 1, h);
        int Csum = find_max_cross_array(A, l, m, h);
        return max(Lsum, max(Rsum, Csum));
    }
}

int main() {
    int arr[] = { 2, 3, 4, 5, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int max_sum = find_max_subarray(arr, 0, n - 1);
    cout << "Maximum contiguous sum is " << max_sum;
    return 0;
}

