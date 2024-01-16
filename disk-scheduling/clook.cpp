#include <iostream>
#include <vector>

using namespace std;

pair<int, int> scan(vector<int> &rq, int current_head) {
    int head = current_head, distance = 0;
    vector<int> seq;
    sort(rq.begin(), rq.end());
    auto it = lower_bound(rq.begin(), rq.end(), head);
    int midPos;
    int var = 1;
    while (var == 1) {
        if (head < *it) {
            midPos = it - rq.begin();
            var = 0;
        } else {
            ++it;
            midPos = it - rq.begin();
        }
    }

    for (int i = midPos; i < rq.size(); i++) {
        distance += abs(rq[i] - current_head);
        current_head = rq[i];
        seq.push_back(rq[i]);
    }

    cout << distance << endl;
    for (int i = 0; i < midPos; i++) {
        distance += abs(rq[i] - current_head);
        current_head = rq[i];
        seq.push_back(rq[i]);
    }
    cout << distance << endl;
    cout << "Seek sequence is: " << head << "-->";
    for (int i = 0; i < seq.size(); i++) {
        if (i == seq.size() - 1) {
            cout << seq[i];
        } else {
            cout << seq[i] << "-->";
        }
    }

    cout << endl;

    return make_pair(midPos, distance);  // Return the total seek distance
}

int main() {
    int qsize, current_head;
    cout << "Enter the queue size: ";
    cin >> qsize;

    vector<int> requests;
    requests.resize(qsize);
    cout << "Enter the values of request queue:" << endl;
    for (int i = 0; i < qsize; i++) {
        cin >> requests[i];
    }

    cout << "Enter the current position of the head: ";
    cin >> current_head;

    pair<int, int> seek_distance = scan(requests, current_head);

    cout << "Total seek distance: " << seek_distance.first << " " << seek_distance.second << endl;

    return 0;
}
