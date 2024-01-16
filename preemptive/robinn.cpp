#include <iostream>
#include <queue>
#include<climits>

using namespace std;

class sequencing {
    int burst_time;
    int arrival_time;
    int waiting_time;
    int tat;
    int remaining_time;
    int status;

public:
    void input(int);
    void output(int);
    void round_robin(int, sequencing[]);
    int minimum(int, sequencing[]);
};

#define max 200

queue<int> rr_queue; // globally declared queue to hold processes

void sequencing::input(int i) {
    cout << "\n  p[" << i + 1 << "]  \nBurst : ";
    cin >> burst_time;
    cout << "arrival : ";
    cin >> arrival_time;
    status = 1; // pending
    remaining_time = burst_time;
}

void sequencing::output(int i) {
    cout << "P[" << i + 1 << "]    \t" << burst_time << "\t\t" << arrival_time << "  \t" << waiting_time << "\t\t" << tat << endl;
}

void sequencing::round_robin(int n, sequencing *p) {
   
    int total_time = minimum(n, p);
    int time_lapse;
    // total time stores number of seconds run

    float avg_wt=0;
    float avg_tat=0;

    cout << "Enter time lapse:\n";
    cin >> time_lapse;

    while(true){

        for(int i=0; i<n; i++){
            if(p[i].remaining_time == total_time){
                rr_queue.push(i);
            }
        }

        if(rr_queue.empty()){
            break;
        }

        int k = rr_queue.front();
        rr_queue.pop();

        int time = min(p[k].remaining_time, time_lapse);

        total_time += time;

        p[k].remaining_time -= time;

        if (p[k].remaining_time == 0) {
            p[k].status = 2; // finished
            p[k].tat = total_time - p[k].arrival_time;
            avg_tat += p[k].tat;
            p[k].waiting_time = p[k].tat - p[k].burst_time;
            avg_wt += p[k].waiting_time;
        } else {
            rr_queue.push(k);
        }
    }
    cout << avg_wt/n << endl;
    cout << avg_tat/n << endl;
}

int sequencing::minimum(int n, sequencing p[]) {
    int min = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (p[i].arrival_time < min) {
            min = p[i].arrival_time;
        }
    }

    return min;
}

int main() {
    int n;
    cout << "Enter the number of processes:\n";
    cin >> n;

    sequencing *p;
    p = new sequencing[n];

    for (int i = 0; i < n; i++) {
        p[i].input(i);
    }

    sequencing x;
    x.round_robin(n, p);

    cout << "\nProcess   Burst Time   Arrival Time  Waiting Time TAT:\n";
    
    for (int i = 0; i < n; i++) {
        p[i].output(i);
    }

    return 0;
}
