class TaskManager {
public:
    unordered_map<int, int> Task_pq;
    unordered_map<int, int> Task_user;
    priority_queue<pair<int, int>> Pq_task;
    TaskManager(vector<vector<int>>& tasks) {
        for(int i = 0; i < tasks.size(); i++){
            int user = tasks[i][0];
            int task = tasks[i][1];
            int pq = tasks[i][2];
            Pq_task.push({pq, task});
            Task_pq[task] = pq;
            Task_user[task] = user;
        }
    }
    
    void add(int userId, int taskId, int priority) {
        Pq_task.push({priority, taskId});
        Task_pq[taskId] = priority;
        Task_user[taskId] = userId;
    }
    
    void edit(int taskId, int newPriority) {
        Task_pq[taskId] = newPriority;
        Pq_task.push({newPriority, taskId});
    }
    
    void rmv(int taskId) {
        Task_pq[taskId] = -1;
    }
    
    int execTop() {

        while(!Pq_task.empty()){
            auto [pq, task] = Pq_task.top();
            Pq_task.pop();
            if(pq == Task_pq[task]){
                Task_pq[task] = -1;
                return Task_user[task];
            }
        }

        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */