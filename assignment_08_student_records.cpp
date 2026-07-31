#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Student {
    string name;
    int id;
    vector<double> scores;
};

void addStudent(vector<Student>& students) {
    Student s;
    cout << "Student name: ";
    getline(cin >> ws, s.name);
    cout << "Student ID: ";
    cin >> s.id;
    int n;
    cout << "How many scores? ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        double score;
        cout << "Enter score " << i + 1 << ": ";
        cin >> score;
        s.scores.push_back(score);
    }
    students.push_back(s);
    cout << "Student \"" << s.name << "\" added successfully." << endl;
}

void displayAll(vector<Student>& students) {
    if (students.empty()) {
        cout << "No students added yet." << endl;
        return;
    }
    for (auto& s : students) {
        double sum = 0;
        for (double sc : s.scores) sum += sc;
        double avg = sum / s.scores.size();
        cout << "Name: " << s.name << " | ID: " << s.id << " | Scores: ";
        for (double sc : s.scores) cout << sc << " ";
        cout << "| Average: " << fixed << setprecision(2) << avg << endl;
    }
}

void calcAverage(vector<Student>& students) {
    int id;
    cout << "Enter student ID: ";
    cin >> id;
    for (auto& s : students) {
        if (s.id == id) {
            double sum = 0;
            for (double sc : s.scores) sum += sc;
            double avg = sum / s.scores.size();
            cout << s.name << "'s average score: " << fixed << setprecision(2) << avg << endl;
            return;
        }
    }
    cout << "Error: Student ID not found." << endl;
}

int main() {
    vector<Student> students;
    int choice;

    while (true) {
        cout << "\n================================" << endl;
        cout << "   STUDENT RECORD SYSTEM MENU" << endl;
        cout << "================================" << endl;
        cout << "1. Add student" << endl;
        cout << "2. Display all students" << endl;
        cout << "3. Calculate average score" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        if (choice == 1) addStudent(students);
        else if (choice == 2) displayAll(students);
        else if (choice == 3) calcAverage(students);
        else if (choice == 4) {
            cout << "Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Please enter 1-4." << endl;
        }
    }
    return 0;
}