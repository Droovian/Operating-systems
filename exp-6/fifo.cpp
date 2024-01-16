#include<iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

void fifoPageReplacement(const vector<int>&referenceString, int capacity){
    int pageFaults = 0;

    queue<int>pageQueue;
    unordered_set<int> pageSet;

    for(int i=0; i<referenceString.size(); i++){
        int currentPage = referenceString[i];

        if(pageSet.find(currentPage) != pageSet.end()){ // O(1)
            cout << "page" << currentPage << "is already in memory (Page Hit)";
        }
        else{
            ++pageFaults;

            if(pageQueue.size() == capacity){
                int oldestPage = pageQueue.front();
                pageQueue.pop();
                pageSet.erase(oldestPage);
            }

            pageQueue.push(currentPage);
            pageSet.insert(currentPage);

            cout << "Page " << currentPage << " is loaded into memory (Page Fault)\n";
        }
    }
    cout << "Total Page Faults: " << pageFaults << endl;
}

int main()
{
    int capacity;
    cout << "Enter the capacity of the memory: ";
    cin >> capacity;

    int n;
    cout << "Enter the number of reference string elements: ";
    cin >> n;

    vector<int> referenceString(n);
    cout << "Enter the reference string elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> referenceString[i];
    }

    fifoPageReplacement(referenceString, capacity);
    return 0;
}