#include <iostream>
#include <vector>
#include <string>
using namespace std;

void addTask(vector<string>& tasks) {
    string task;
    cout << "Enter task: ";
    getline(cin >> ws, task);
    tasks.push_back(task);
    cout << "Task added: \"" << task << "\"" << endl;
}

void viewTasks(vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks yet! Your list is empty." << endl;
        return;
    }
    cout << "Your Tasks:" << endl;
    for (int i = 0; i < (int)tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}

void deleteTask(vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to delete!" << endl;
        return;
    }
    viewTasks(tasks);
    int num;
    cout << "Enter task number to delete: ";
    cin >> num;
    if (num < 1 || num > (int)tasks.size()) {
        cout << "Error: Invalid task number." << endl;
        return;
    }
    cout << "Task \"" << tasks[num - 1] << "\" has been removed." << endl;
    tasks.erase(tasks.begin() + num - 1);
}

int main() {
    vector<string> tasks;
    int choice;

    while (true) {
        cout << "\n==========================" << endl;
        cout << "      TO-DO LIST MENU" << endl;
        cout << "==========================" << endl;
        cout << "1. Add task" << endl;
        cout << "2. View tasks" << endl;
        cout << "3. Delete task" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        if (choice == 1) addTask(tasks);
        else if (choice == 2) viewTasks(tasks);
        else if (choice == 3) deleteTask(tasks);
        else if (choice == 4) {
            cout << "Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Please enter 1-4." << endl;
        }
    }
    return 0;
}