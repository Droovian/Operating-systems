#include<iostream>
using namespace std;

int total_head_movement = 0, n, current_head;
int request[30];

void right_display(){

    
}

void left_display(){

}

int main()
{
    int block, direction;
    cout << "Enter the Block Size of the Disk: ";
    cin >> block;
    cout << "Enter the number of Disk Requests: ";
    cin >> n;
    cout << "Enter the Disk Requests to be Searched : ";
    for (int i = 0; i < n; i++)
        scanf("%d", &request[i]);
    sort(request, request + n);
    cout << endl;
    cout << "Enter the Current Disk Head Position: ";
    cin >> current_head;
    cout << "Enter Direction [Left - 0; Right - 1]: ";
    cin >> direction;
    cout << "Track sequence: " << current_head << " ";
    if (direction == 0)
    {
        total_head_movement += (current_head - request[0]);
        total_head_movement += (request[n - 1] - request[0]);
        left_display();
    }
    else
    {
        total_head_movement += (request[n - 1] - current_head);
        total_head_movement += (request[n - 1] - request[0]);
        right_display();
    }
    cout << endl
         << "The Total Disk Head Movement is: " << total_head_movement;
    return 0;
}