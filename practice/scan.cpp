#include <iostream>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;

int scan(vector<int> &rq, int& current_head, int& limit) {
    
    int head = current_head; int temp;
    int total = 0;

    sort(rq.begin(), rq.end());
    // 10 27 41 64 110 120 129 147 160 186
    auto it = lower_bound(rq.begin(), rq.end(), current_head);

    int position = distance(rq.begin(), it);

    for(int i=position; i<rq.size(); i++){
        total += abs(rq[i] - head);
        head = rq[i];
    }

    temp = (limit-1) - rq[rq.size()-1];

    total += temp*2;
    
    total += abs(rq[position-2] - head);
    head = rq[position-2];

    for(int i=position-2; i>=0; i--){
        total += abs(rq[i] - head);
        head = rq[i];
    }


    return total;
}

int main() {
//    vector<int> requests = {98, 183, 37, 122, 14, 124, 65, 67};
//    int current_head = 53;
	int qsize,current_head, limit;
		cout <<"enter the queue size:";
		cin>>qsize;
		vector<int> requests;
		requests.resize(qsize);
		cout<<"enter the values of request queue"<<endl;
		for(int i =0;i<qsize;i++){
			cin>>requests[i];
		}
		cout<<"enter the current pos of head"<<endl;
		cin>>current_head;
        cout << "Enter the limit:\n";
        cin >> limit;
    int seek_distance = scan(requests, current_head, limit);

    cout << "Total seek distance: " << seek_distance << endl;

    return 0;
}