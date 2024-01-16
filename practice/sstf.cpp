#include<iostream>
#include<vector>

using namespace std;

int solver(vector<int>&requests, int &current_head){

    vector<int>soln; int distance = 0;

    while(!requests.empty()){

        int min = INT_MAX;
        int min_index = -1;

        for(int i=0; i<requests.size(); i++){

            int seek = abs(current_head - requests[i]);

            if(seek < min){
                min = seek;
                min_index = i;
            }
        }

        soln.push_back(requests[min_index]);
        distance +=min;
        current_head = requests[min_index];
        requests.erase(requests.begin() + min_index);
    }

    return distance;
}

int main()
{
    int n, current_head;
    cout << "Enter number of elements in the track:\n";
    cin >> n;

    vector<int>sstf;

    sstf.resize(n);

    for(int i=0; i<n; i++){
        cin >> sstf[i];
    }

    cout << "Please enter the position at which the head pointer lies:\n";
    cin >> current_head;

    int time = solver(sstf, current_head);

    cout << "Total distance head will travel is" << time << endl;
    return 0;
}