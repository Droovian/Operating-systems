#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

#define pending 1
#define finished 2

using namespace std;

class sequencing{

        int burst_time;
        int arrival_time;
        int waiting_time;
        int tat;
        int remaining_time;
        int status;

    public:
        void input(int);
        void output(int);
        void srtn(int, sequencing *);
        int minimum(int, sequencing *);

};

    void sequencing::input(int n){ // taking input for bt, at, setting status and remaining time

        cout << "Burst time:\n";
        cin >> burst_time;
        cout << "Arrival time:\n";
        cin >> arrival_time;
        status = pending;
        remaining_time = burst_time;
    }

    void sequencing::srtn(int n, sequencing *p){

        int total_time = minimum(n, p); // arrival time which is lowest

        float avg_wt = 0;
        float avg_tat = 0;

        while(true){ // do this until all processes are finished executing

            int high_value = INT_MAX;
            int k = -1;

            for(int j=0; j<n; j++){ // go through all processes

                if(p[j].status == pending && p[j].remaining_time < high_value && p[j].arrival_time <= total_time){
                    // if the process is pending, it has arrived already and has the lowest remaining time left for execution

                    k = j; // set k to that process
                    high_value = p[j].remaining_time;
                }
            }

            if(k == -1){ // if no process is pending break out of the while loop
                break;
            }

            int j,check = 0; // check is a flag to determine if another process arrives while one is executing

            for(j=0; j<p[k].remaining_time; j++){
                for(int l=0; l<n; l++){
                    if(l != k && p[l].arrival_time == total_time + j && p[l].remaining_time < (p[k].remaining_time - j)){
                        // if l is not same as k and another process has arrived in the time span j and its remaining time of execution
                        // is lesser than that of the currently executing process, j denotes how much the selected process k has executed
                        check = 1;
                        break;
                    }
                }

                if(check){
                    break;
                }
            }

            total_time += j;

            if(j == p[k].remaining_time){
                p[k].status = finished;
                p[k].tat = total_time - p[k].arrival_time;
                avg_tat += p[k].tat;
                p[k].waiting_time = p[k].tat - p[k].burst_time;
                avg_wt += p[k].waiting_time;
            }
            else{
                p[k].remaining_time -=j;
            }
            cout << "|__P[" << k + 1 << "]__|" << total_time;
            // now check if all processes have finished executing

            int check_process = 0;

            for(int i=0; i<n; i++){
                if(p[i].status == pending){
                    check_process = 1;
                }
            }

            if(!check_process){
                break;
            }
        }

        cout << "Average waiting time of the processes are:\n" << avg_wt / n << endl;
        cout << "Average turn around time of the processes are:\n" << avg_tat / n << endl;
    }

     void sequencing::output(int i) {
        cout << "P[" << i + 1 << "]    \t" << burst_time << "\t\t" << arrival_time << "  \t" << waiting_time << "\t\t" << tat << endl;
    }

    int sequencing::minimum(int n, sequencing *p){

        int mini = INT_MAX;

        for(int i=0; i<n; i++){
            if(p[i].arrival_time < mini){
                mini = p[i].arrival_time;
            }
        }
        return mini;
    }

int main()
{
    int n;
    cout << "Enter the number of processes:\n";
    cin >> n;

    sequencing *p;

    p = new sequencing[n]; // allocating heap memory

    for(int i=0; i<n; i++){
        p[i].input(i);
    }

    sequencing x;

    x.srtn(n, p);

    cout << "\nProcess   BT   AT  WT   TAT:\n";
    
    for(int i=0; i<n; i++){
        p[i].output(i);
    }

    return 0;
}