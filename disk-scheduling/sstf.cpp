#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>

using namespace std;

int sstf(vector<int> &requests, int &head){

    int seek_time = 0;

    vector<int>seekSequence; // using this vector to print the seek sequence

    while(!requests.empty()){

        int min = INT_MAX;
        int min_index = -1;

        for(int i=0; i<requests.size(); i++){
            int seek = abs(head - requests[i]);

            if(seek < min){
                min = seek;
                min_index = i;
            }
        }

        seekSequence.push_back(requests[min_index]);
        seek_time += min;
        head = requests[min_index];
        requests.erase(requests.begin() + min_index);

    }

    cout << "seek sequence is: " << head << "-->";
    for(int i=0; i<seekSequence.size(); i++){
        cout << seekSequence[i] << "-->";
    }

    return seek_time;
}

int main()
{
    int q_size, current_head;

    cout << "Enter the queue size:\n";
    cin >> q_size;

    vector<int>requests;

    requests.resize(q_size);

    for(int i=0; i<q_size; i++){
        cin >> requests[i];
    }

    cout << "Enter the position of the head:\n";
    cin >> current_head;

    int seek_time = sstf(requests, current_head);

    cout << "Total seek time is: \n" << seek_time;
    return 0;
}