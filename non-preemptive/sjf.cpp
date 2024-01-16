#include<iostream>
#include <algorithm>
using namespace std;

class sjf{
    public:
        int process;
        int burst_time;
        int waiting_time;
        int tat;
        int arrival_time;

    void get_data(int n);
    void print_wait();
    void print_tat();

};

    void sjf::print_wait(){
        cout << waiting_time << endl;
    }

    void sjf::print_tat(){
        cout << tat << endl;
    }

    void calculate_tat(int n, sjf *p){
        int completion_time = p[0].arrival_time;

        for(int i=0; i<n; i++){
            completion_time += p[i].burst_time;
            p[i].tat = completion_time - p[i].arrival_time;
        }
    }

    void calculate_wt(int n, sjf *p){
        for (int i = 0; i < n; i++){
            p[i].waiting_time= p[i].tat - p[i].burst_time;
        }
    }

    void calculate_avg(int n, sjf *process, float &avg_wt, float &avg_tat){

        avg_wt=0;
        avg_tat=0;

        for(int i=0; i<n; i++){
            avg_wt += process[i].waiting_time;
            avg_tat += process[i].tat;
        }

        cout << "Average waiting time is:\n" << avg_wt/n << "\n\n";
        cout << "Average Tat is:\n" << avg_tat/n << "\n\n";

    }
    bool compareValue(sjf & a,sjf & b){
            if(a.arrival_time == b.arrival_time)
                 return a.burst_time < b.burst_time;
            else{
                 return a.arrival_time < b.arrival_time;
             }
        }

    void sjf::get_data(int n){
        cout << "Enter burst time of process:";
        cin >> burst_time;
        cout << "Enter arrival time of process:";
        cin >> arrival_time;
    }

int main()
{
    int n; float avg_wt, avg_tat;

    cout << "Enter no of processes:";
    cin >> n;

    sjf process[n];

    for(int i=0; i<n; i++){
        process[i].process = i+1;
        process[i].get_data(n);
    }

    sort(process, process+n, compareValue);
    calculate_tat(n, process);
    calculate_wt(n, process);
   
    cout << "waiting time of processes is:\n";

    for(int i=0; i<n; i++){
        process[i].print_wait();
    }
    
    cout << "tat for processes is:\n";

    for(int i=0; i<n; i++){
        process[i].print_tat();
    }

    cout << "\n\n";

    calculate_avg(n, process, avg_wt, avg_tat);

    return 0;
}