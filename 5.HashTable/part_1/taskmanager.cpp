#include <bits/stdc++.h>
using namespace std;

class TaskManager {
private:
    unordered_map<int, pair<int, int>> taskMap;
    set<pair<int, int>> prioritySet;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto& task : tasks) {
            add(task[0], task[1], task[2]);
        }
    }

    void add(int userId, int taskId, int priority) {
        taskMap[taskId] = {userId, priority};
        prioritySet.insert({-priority, -taskId});
    }

    void edit(int taskId, int newPriority) {
        auto [userId, oldPriority] = taskMap[taskId];
        prioritySet.erase({-oldPriority, -taskId});
      
        prioritySet.insert({-newPriority, -taskId});
        taskMap[taskId] = {userId, newPriority};
    }

    void rmv(int taskId) {
        auto [userId, priority] = taskMap[taskId];
        prioritySet.erase({-priority, -taskId});
      
        taskMap.erase(taskId);
    }

    int execTop() {
        if (prioritySet.empty()) return -1;
      
        auto topTask = *prioritySet.begin();
        prioritySet.erase(prioritySet.begin());
      
        int taskId = -topTask.second;
        int userId = taskMap[taskId].first;
        taskMap.erase(taskId);
      
        return userId;
    }
};

int main() {

    return 0;
}