#include <iostream>
using namespace std;
 
class process {
public:
    int pid, arr_time, burst_time, priority, wait_time, ta_time, completion_time;
};

bool comp(process a, process b) {
    if (a.arr_time == b.arr_time) {
        return a.priority < b.priority;
    } else {
        return a.arr_time < b.arr_time;
    }
}

void cal_tat(int n, process p[]) {
    int completion = p[0].arr_time;
    for (int i = 0; i < n; i++) {
        completion = completion + p[i].burst_time;
        p[i].completion_time = completion;
        p[i].ta_time = completion - p[i].arr_time;
    }
}

void cal_wt(int n, process p[]) {
    for (int i = 0; i < n; i++) {
        p[i].wait_time = p[i].ta_time - p[i].burst_time;
    }
}
 
int main() {
    int num;
    cout << "Enter number of processes: ";
    cin >> num;

    process pro[num];

    cout << "Enter arrival time, burst time and priority of processes: " << endl;
    for (int i = 0; i < num; i++) {
        cout << "P" << i << ": ";
        cin >> pro[i].arr_time;
        cin >> pro[i].burst_time;
        cin >> pro[i].priority;
        pro[i].pid = i;
        cout << endl;
    }

    sort(pro, pro + num, comp);

    cal_tat(num, pro);
    cal_wt(num, pro);

    cout << "Gantt Chart" << endl;
    cout << pro[0].arr_time << "     ";
    for (int i = 0; i < num; i++) {
        cout << "|P" << pro[i].pid << "|   " << pro[i].completion_time << "     ";
    }
    return 0;
}