#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Structure to represent a task
struct Task {
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}
};

// Vector to store tasks
vector<Task> tasks;

// Function prototypes
void addTask();
void viewTasks();
void markCompleted();
void removeTask();

int main() {
    int choice;

    while (true) {
        cout << "\n==== TO-DO LIST MANAGER ====" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markCompleted();
                break;
            case 4:
                removeTask();
                break;
            case 5:
                cout << "Thank you for using the To-Do List Manager. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 5." << endl;
                break;
        }
    }

    return 0;
}

// Function to add a task to the list
void addTask() {
    string description;
    cout << "Enter the task to add: ";
    cin.ignore(); // Clear input buffer
    getline(cin, description);

    tasks.push_back(Task(description));
    cout << "Task added successfully!" << endl;
}

// Function to view all tasks in the list with their status
void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks to show." << endl;
    } else {
        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description << " - "
                 << (tasks[i].completed ? "Completed" : "Pending") << endl;
        }
    }
}

// Function to mark a task as completed
void markCompleted() {
    viewTasks(); // Display current tasks for user to choose from
    if (!tasks.empty()) {
        int index;
        cout << "Enter the task number to mark as completed: ";
        cin >> index;
        if (index > 0 && index <= static_cast<int>(tasks.size())) {
            tasks[index - 1].completed = true;
            cout << "Task '" << tasks[index - 1].description << "' marked as completed." << endl;
        } else {
            cout << "Invalid task number. Please try again." << endl;
        }
    }
}

// Function to remove a task from the list
void removeTask() {
    viewTasks(); // Display current tasks for user to choose from
    if (!tasks.empty()) {
        int index;
        cout << "Enter the task number to remove: ";
        cin >> index;
        if (index > 0 && index <= static_cast<int>(tasks.size())) {
            tasks.erase(tasks.begin() + index - 1);
            cout << "Task removed successfully." << endl;
        } else {
            cout << "Invalid task number. Please try again." << endl;
        }
    }
}
