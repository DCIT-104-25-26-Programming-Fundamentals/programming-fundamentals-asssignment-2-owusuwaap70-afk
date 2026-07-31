#include <iostream>
using namespace std;

void printSingleTable(int n) {
    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return;
    }
    cout << "Multiplication Table for " << n << ":" << endl;
    for (int i = 1; i <= 12; i++) {
        cout << n << " x " << i << " = " << n * i << endl;
    }
}

void printAllTables(int n) {
    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        printSingleTable(i);
        cout << "----------------------------" << endl;
    }
}

int main() {
    // Part A
    int num;
    cout << "=== PART A: Single Table ===" << endl;
    cout << "Enter a number: ";
    cin >> num;
    printSingleTable(num);

    // Part B
    int n;
    cout << "\n=== PART B: Tables from 1 to N ===" << endl;
    cout << "Enter N: ";
    cin >> n;
    printAllTables(n);

    return 0;
}