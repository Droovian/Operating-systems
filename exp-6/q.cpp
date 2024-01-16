#include<iostream>
#include<queue>

using namespace std;

void showq(queue<int> gq)
{
    queue<int> g = gq;
    while (!g.empty()) {
        cout << '\t' << g.front();
        g.pop();
    }
    cout << '\n';
}

int main()
{
    queue<int>q1;

    q1.push(10);
    q1.push(20);
    q1.push(30);

    showq(q1);
    q1.pop();

    q1.push(50);
    showq(q1);
    return 0;
}