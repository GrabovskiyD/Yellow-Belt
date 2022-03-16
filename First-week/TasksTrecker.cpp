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

void TaskStatusUpdate(TaskStatus& task_status){
    switch(task_status){
        case TaskStatus::NEW:
            task_status = TaskStatus::IN_PROGRESS;
            break;
        case TaskStatus::IN_PROGRESS:
            task_status = TaskStatus::TESTING;
            break;
        case TaskStatus::TESTING:
            task_status = TaskStatus::DONE;
            break;
    }
}

void PrintTasksInfo(TasksInfo tasks_info) {
  cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
      ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
      ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
      ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

class TeamTasks{
public:
    const TasksInfo& GetPersonTasksInfo(const string& person) const{
        return persons_tasks.at(person);
    }

    void AddNewTask(const string& person){
        persons_tasks[person][TaskStatus::NEW]++;
    }

    tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count){
        while(task_count > 0){
            for()
        }
    }
private:
    map<string, TasksInfo> persons_tasks;
};

int main(){

    return 0;
}