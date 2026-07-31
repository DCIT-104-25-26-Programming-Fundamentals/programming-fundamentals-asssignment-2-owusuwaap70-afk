#include <iostream>
using namespace std;

void printFibonacci(int n) {
    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return;
    }
    int a = 0, b = 1;
    cout << "Fibonacci sequence: ";
    for (int i = 0; i < n; i++) {
        cout << a;
        if (i < n - 1) cout << " ";
        int temp = a + b;
        a = b;
        b = temp;
    }
    cout << endl;
}

bool isFibonacci(int num) {
    if (num < 0) return false;
    int a = 0, b = 1;
    while (a < num) {
        int temp = a + b;
        a = b;
        b = temp;
    }
    return a == num;
}

int main() {
    // Part A
    int n;
    cout << "How many terms? ";
    cin >> n;
    printFibonacci(n);

    // Part B
    int num;
    cout << "\nEnter a number to check: ";
    cin >> num;
    if (isFibonacci(num)) {
        cout << num << " is a Fibonacci number." << endl;
    } else {
        cout << num << " is NOT a Fibonacci number." << endl;
    }

    return 0;
}