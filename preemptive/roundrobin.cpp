#include <iostream>
#include <queue>
using namespace std;

class sequencing {
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
    int remaining_time;
    int status;

public:
    void input(int);
    void output(int);
    void round_robin(int, sequencing[]);
    int minimum(int, sequencing[]);
};

#define max 200

queue<int> rr_queue;

void sequencing::input(int i) {
    cout << "\n<<  P[" << i + 1 << "]  >>\nBURST TIME : ";
    cin >> burst_time;
    cout << "ARRIVAL TIME : ";
    cin >> arrival_time;
    status = 1; // pending
    remaining_time = burst_time;
}

void sequencing::output(int i) {
    cout << "P[" << i + 1 << "]    \t" << burst_time << "\t\t" << arrival_time << "  \t" << waiting_time << "\t\t" << turnaround_time << endl;
}

void sequencing::round_robin(int n, sequencing p[]) {
    int total_time = minimum(n, p);
    int time_lapse;

    cout << "Enter the time lapse : ";
    cin >> time_lapse;

    float avg_waiting_time = 0;
    float avg_turnaround_time = 0;

    cout << "GANTT CHART : " << total_time;
    
    while (true) {
        for (int i = 0; i < n; i++) {
            if (p[i].arrival_time == total_time) {
                rr_queue.push(i);
            }
        }

        if (rr_queue.empty()) { // important 
            break;
        }

        int k = rr_queue.front();
        rr_queue.pop();

        int time = min(time_lapse, p[k].remaining_time);

        total_time += time;
        p[k].remaining_time -= time;

        if (p[k].remaining_time == 0) {
            p[k].status = 2; // finished
            p[k].turnaround_time = total_time - p[k].arrival_time;
            avg_turnaround_time += p[k].turnaround_time;
            p[k].waiting_time = p[k].turnaround_time - p[k].burst_time;
            avg_waiting_time += p[k].waiting_time;
        } else {
            rr_queue.push(k);
        }
    }

    cout << "|";
    cout << "\nAVERAGE WAITING TIME : " << avg_waiting_time / n;
    cout << "\nAVERAGE TURN AROUND TIME : " << avg_turnaround_time / n << endl;
}

int sequencing::minimum(int n, sequencing p[]) {
    int min = 9999;

    for (int i = 0; i < n; i++) {
        if (p[i].arrival_time < min) {
            min = p[i].arrival_time;
        }
    }

    return min;
}

int main() {
    int n;
    cout << "ENTER THE NUMBER OF JOBS : ";
    cin >> n;

    sequencing *p;
    p = new sequencing[n];

    for (int i = 0; i < n; i++) {
        p[i].input(i);
    }

    sequencing x;
    x.round_robin(n, p);

    cout << "\nProcess   BURST_Time   Arrival_Time  Waiting_Time Turnaround_Time:\n";
    
    for (int i = 0; i < n; i++) {
        p[i].output(i);
    }

    return 0;
}
