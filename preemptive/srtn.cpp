#include<iostream>
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
        void srtn(int, sequencing*);
        int minimum(int , sequencing*);

};

    void sequencing::output(int i) {
    cout << "P[" << i + 1 << "]    \t" << burst_time << "\t\t" << arrival_time << "  \t" << waiting_time << "\t\t" << tat << endl;
    }
    
    void sequencing :: input(int n){

        cout << "Burst time:\n";
        cin >> burst_time;
        cout << "arrival time:\n";
        cin >> arrival_time;
        status=pending;
        remaining_time = burst_time;

    }

    void sequencing::srtn(int n, sequencing *p){

        int total_time = minimum(n, p);
        float avg_waiting_time = 0;
        float avg_turnaround_time = 0;

        while(true){

            int rt = INT_MAX;
            int k = -1;

            for(int j=0; j<n; j++){
                if(p[j].status == pending && p[j].remaining_time < rt && p[j].arrival_time <= total_time){
                    k = j;
                    rt = p[j].remaining_time;
                }
            }

            if(k == -1){
                break;
            }

            int j, check=0;

            for(j=0; j<p[k].remaining_time; j++){
                for(int l=0; l<n; l++){
                    if(l != k && p[l].arrival_time == total_time + j && p[l].remaining_time < (p[k].remaining_time - j)){
                        check = 1;
                        break;
                    }
                }
                if(check){
                    break;
                }
            }

            total_time += j;

            if (j == p[k].remaining_time) {
                    p[k].status = finished;
                    p[k].tat = total_time - p[k].arrival_time;
                    avg_turnaround_time += p[k].tat;
                    p[k].waiting_time = p[k].tat - p[k].burst_time;
                    avg_waiting_time += p[k].waiting_time;
            } 
            else {
                p[k].remaining_time -= j;
            }
            cout << "|__P[" << k + 1 << "]__|" << total_time;

            int if_finished = 0;
            for (int i = 0; i < n; i++)
                if (p[i].status == pending)
                    if_finished = 1;

            if (!if_finished) break;
        }
        cout << "|";
        cout << "\nAVERAGE WAITING TIME : " << avg_waiting_time / n;
        cout << "\nAVERAGE TURN AROUND TIME : " << avg_turnaround_time / n << endl;
    }

    int sequencing::minimum(int n, sequencing *p){
        int min = INT_MAX;
        for(int i=0; i<n; i++){
            if(p[i].arrival_time < min){
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
    for (int i = 0; i < n; i++)
        p[i].input(i);
    sequencing x;
    x.srtn(n, p);
    cout << "\nProcess   BURST_Time   Arrival_Time  Waiting_Time Turnaround_Time:\n";
    for (int i = 0; i < n; i++)
        p[i].output(i);
    return 0;
}