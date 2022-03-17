#include <iostream>
#include <map>
#include <tuple>
#include <vector>

using namespace std;

enum class TaskStatus{
    NEW,
    IN_PROGRESS,
    TESTING,
    DONE
};

using TasksInfo = map<TaskStatus, int>;

TaskStatus TaskStatusUpdate(TaskStatus& task_status){
    return static_cast<TaskStatus>(static_cast<int>(task_status) + 1);
}

void PrintTasksInfo(TasksInfo tasks_info) {
  cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
      ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
      ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
      ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

void RemoveZeros(TasksInfo& tasks_info){
    vector<TaskStatus> statuses_to_remove;
    for(const auto& task : tasks_info){
        if(task.second == 0){
            statuses_to_remove.push_back(task.first);
        }
    }
    for(const auto& status : statuses_to_remove){
        tasks_info.erase(status);
    }
}

class TeamTasks{
public:
    const TasksInfo& GetPersonTasksInfo(const string& person) const{
        return persons_tasks.at(person);
    }

    void AddNewTask(const string& person){
        ++persons_tasks[person][TaskStatus::NEW];
    }

    tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count){
        TasksInfo updated_tasks, untouched_tasks;
        TasksInfo& tasks = persons_tasks[person];
        for(TaskStatus status = TaskStatus::NEW; status != TaskStatus::DONE; status = TaskStatusUpdate(status)){
            updated_tasks[TaskStatusUpdate(status)] = min(task_count, tasks[status]);
            task_count -= updated_tasks[TaskStatusUpdate(status)];
        }
        
        for (TaskStatus status = TaskStatus::NEW; status != TaskStatus::DONE; status = TaskStatusUpdate(status)) {
            untouched_tasks[status] = tasks[status] - updated_tasks[TaskStatusUpdate(status)];
            tasks[status] += updated_tasks[status] - updated_tasks[TaskStatusUpdate(status)];
        }
        tasks[TaskStatus::DONE] += updated_tasks[TaskStatus::DONE];

        RemoveZeros(updated_tasks);
        RemoveZeros(untouched_tasks);
        RemoveZeros(persons_tasks.at(person));

        return {updated_tasks, untouched_tasks};
    }
private:
    map<string, TasksInfo> persons_tasks;
};

int main(){
    TeamTasks tasks;
    tasks.AddNewTask("Ilia");
    for (int i = 0; i < 3; ++i) {
        tasks.AddNewTask("Ivan");
    }
    cout << "Ilia's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
    cout << "Ivan's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
  
    TasksInfo updated_tasks, untouched_tasks;
  
    tie(updated_tasks, untouched_tasks) =
        tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);
  
    tie(updated_tasks, untouched_tasks) =
        tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);
    return 0;
}