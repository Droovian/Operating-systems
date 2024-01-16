#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int arr[] = {10, 27, 41, 64, 110, 120, 129, 147, 160, 186};
    vector<int> requests(arr, arr + sizeof(arr) / sizeof(arr[0]));

    int head = 100;
    auto it = lower_bound(requests.begin(), requests.end(), head);

    if (it != requests.end()) {
        cout << *it;
    } else {
        cout << "No request found greater than or equal to the head.";
    }

    return 0;
}