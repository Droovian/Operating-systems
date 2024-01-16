#include<iostream>
#include <vector>
#include<math.h>

using namespace std;

void FCFS(int *arr, int head, int n){
    int distance = 0;

    for(int i=0; i<n-1; i++){
        distance += abs(arr[i] - arr[i+1]);
    }

    // add it to head

    distance += abs(head - arr[0]);

    cout << "Total head movements are: " << " " << distance;

}


int main()
{
    int size,head;

    cout << "Enter size of the request array:\n";
    cin >> size;

    int seek[100];

    cout << "Enter elements for the request queue:\n";

    for(int i=0; i<size; i++){
        cin >> seek[i];
    }

    cout << "What's the position of the head?\n";
    cin >> head;

    FCFS(seek, head, size);

    
    return 0;
}