#include "TaskManager.hpp"

bool operator<(const Task& a, const Task& b) {
    if (a.getPriority() != b.getPriority()) {
        return a.getPriority() < b.getPriority();
    }
    
    if (a.getDuration() != b.getDuration()) {
        return a.getDuration() > b.getDuration();
    }
    
    return a.getId() > b.getId();
}

void TaskManager::add(const string& id, const string& title, int priority, int duration) {
        tasks.push_back(Task(id, title, priority, duration));
}

void TaskManager::add(const Task& task) {
        tasks.push_back(task);
}

void TaskManager::update(const string& id, const string& title, int priority, int duration) {
    for (auto it = tasks.begin() ; it != tasks.end() ; it++) {
        if (it->getId() == id) {
            it->setTitle(title);
            it->setPriority(priority);
            it->setDuration(duration);
            return;
        }
    }
}

bool TaskManager::remove(const string& id) {
    for (auto it = tasks.begin() ; it != tasks.end() ; it++) {
        if (it->getId() == id) {
            tasks.erase(it);
            return true;
        }
    }
    return false;
}

const Task* TaskManager::find(const string& id) const{
    for (const Task& task : tasks) {
        if (task.getId() == id) {
            return &task;
        }
    }
    return nullptr;
}

void TaskManager::sort() {
    int n = tasks.size();
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n - i - 1 ; j++) {
            if (tasks[j] < tasks[j + 1]) {
                swap(tasks[j], tasks[j + 1]);
            }
        }
    }
}

long long TaskManager::totalDuration(long long minPriority) const {
    long long total = 0;
    for (const Task& task : tasks) {
        if (task.getPriority() >= minPriority) {
            total += task.getDuration();
        }
    }
    return total;
}

void TaskManager::print(const string& keyword) const {
    bool empty = true;

    for (const Task& task : tasks) {
        if ((task.getTitle()).find(keyword) != string::npos) {
            empty = false;
            cout << task.getId() << "|" << task.getTitle() << "|" << task.getPriority() << "|" << task.getDuration() << endl;
        }
    }

    if (empty) {
        cout << "EMPTY" << endl;
    }
}

void TaskManager::print() const {
    if (tasks.empty()) {
        cout << "EMPTY" << endl;
        return;
    }
    else {
        for (const Task& task : tasks) {
            cout << task.getId() << "|" << task.getTitle() << "|" << task.getPriority() << "|" << task.getDuration() << endl;
        }
    }
}