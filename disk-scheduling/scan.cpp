#include <iostream>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;

int scan(vector<int> &rq, int current_head) {
    int head = current_head, distance;
    vector<int> seq;
    sort(rq.begin(), rq.end());
    auto it = lower_bound(rq.begin(), rq.end(), head);
    int mid = *it;
    int midPos;
    int var=1;
    while(var==1){
         if (head > *it) {
            midPos = it - rq.begin();
            var=0;
        } else {
            --it;
            midPos = it - rq.begin();
        }
    }
   

    for (int i = midPos; i >= 0; i--) {
        distance += abs(rq[i] - current_head);
        cout << rq[i] << " " << "\n";
        if(i==0){
            distance+=rq[0];
            current_head=0;
            seq.push_back(rq[i]);
            seq.push_back(0);
        }else{
        current_head = rq[i];
        seq.push_back(rq[i]);
        }
    }
    cout << distance << endl;

    for(int i=midPos+1;i<rq.size();i++){
         distance += abs(rq[i] - current_head);
        current_head = rq[i];
        seq.push_back(rq[i]); 
    }
    
    cout << "Seek sequence is: " << head << "-->";
    for (int i = 0; i < seq.size(); i++) {
        
        if (i == seq.size() - 1) {
            cout << seq[i];
        }else{
            cout << seq[i] << "-->";
        }
    }
   
    cout << endl;

    return distance;  // Return the total seek distance
}

int main() {
//    vector<int> requests = {98, 183, 37, 122, 14, 124, 65, 67};
//    int current_head = 53;
	int qsize,current_head;
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
    int seek_distance = scan(requests, current_head);

    cout << "Total seek distance: " << seek_distance << endl;

    return 0;
}