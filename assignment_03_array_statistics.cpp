#include <iostream>
using namespace std;

int computeSum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

double computeAverage(int arr[], int n) {
    return (double)computeSum(arr, n) / n;
}

int computeMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

int computeMin(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
    }
    return min;
}

int main() {
    int n;
    cout << "How many numbers? ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return 1;
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter number " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "\nResults:" << endl;
    cout << "Sum:     " << computeSum(arr, n) << endl;
    cout << "Average: " << computeAverage(arr, n) << endl;
    cout << "Maximum: " << computeMax(arr, n) << endl;
    cout << "Minimum: " << computeMin(arr, n) << endl;

    return 0;
}