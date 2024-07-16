#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Task {
public:
    string description;
    bool finished;

    Task(const string &desc) : description(desc), finished(false) {}
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string &desc) {
        tasks.emplace_back(desc);
        cout << "Task added in list: " << desc << endl;
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks in the list." << endl;
            return;
        }

        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". [" << (tasks[i].finished ? "X" : " ") << "] " << tasks[i].description << endl;
        }
    }

    void markTaskCompleted(int index) {
        if (index < 1 || index > tasks.size()) {
            cout << "Invalid task number." << endl;
            return;
        }
        tasks[index - 1].finished = true;
        cout << "Task marked as finished: " << tasks[index - 1].description << endl;
    }

    void removeTask(int index) {
        if (index < 1 || index > tasks.size()) {
            cout << "Invalid task number." << endl;
            return;
        }
        cout << "Task removed: " << tasks[index - 1].description << endl;
        tasks.erase(tasks.begin() + index - 1);
    }
};

int main() {
    ToDoList todoList;
    int choice;
    string taskDesc;
    int tasknum;

    while (true) {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add Task in list\n";
        cout << "2. View list\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                getline(cin, taskDesc);
                todoList.addTask(taskDesc);
                break;
            case 2:
                todoList.viewTasks();
                break;
            case 3:
                cout << "Enter task number to mark as finished: ";
                cin >> tasknum;
                todoList.markTaskCompleted(tasknum);
                break;
            case 4:
                cout << "Enter task number to remove: ";
                cin >> tasknum;
                todoList.removeTask(tasknum);
                break;
            case 5:
                cout << "Saving and exiting the To-Do List. \nSee you soon!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
