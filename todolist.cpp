#include <iostream>
#include <vector>
#include <string>

class Task {
public:
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

class TodoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& desc) {
        tasks.push_back(Task(desc));
        std::cout << "Task added successfully!\n";
    }

    void viewTasks() {
        if (tasks.empty()) {
            std::cout << "No tasks available.\n";
            return;
        }

        std::cout << "Tasks:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". ";
            if (tasks[i].completed) {
                std::cout << "[Completed] ";
            }
            std::cout << tasks[i].description << "\n";
        }
    }

    void markCompleted(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].completed = true;
            std::cout << "Task marked as completed!\n";
        } else {
            std::cout << "Invalid task index.\n";
        }
    }
};

int main() {
    TodoList todoList;

    while (true) {
        std::cout << "\nTODO List Application\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cin.ignore(); // Clear the newline character from the buffer
                std::cout << "Enter task description: ";
                std::string desc;
                std::getline(std::cin, desc);
                todoList.addTask(desc);
                break;
            }
            case 2:
                todoList.viewTasks();
                break;
            case 3: {
                std::cout << "Enter the index of the task to mark as completed: ";
                size_t index;
                std::cin >> index;
                todoList.markCompleted(index);
                break;
            }
            case 4:
                std::cout << "Exiting program.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
