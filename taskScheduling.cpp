// DAA Lab Week 10 Question 2
// Max tasks completed before deadline

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void maxActivities(int n, vector<int> &dur, vector<int> &deadline)
{
    vector<pair<int, int>> tasks;

    // Pair: (deadline, duration)
    for (int i = 0; i < n; i++)
    {
        tasks.push_back({deadline[i], dur[i]});
    }
    // Sort tasks by deadline
    sort(tasks.begin(), tasks.end());

    priority_queue<int> pq; // Max-heap of durations
    int time = 0;

    for (auto it : tasks)
    {
        int d = it.first;
        int t = it.second;

        if (time + t <= d)
        {
            pq.push(t);
            time += t;
        }
        else if (!pq.empty() && pq.top() > t)
        {
            time -= pq.top();
            pq.pop();
            pq.push(t);
            time += t;
        }
    }
    cout << "Max tasks that can be completed: " << pq.size() << endl;

}

int main()
{
    int n;
    cout << "Enter number of tasks: ";
    cin >> n;

    vector<int> duration(n), deadline(n);

    cout << "Enter durations of tasks:\n";
    for (int i = 0; i < n; i++)
        cin >> duration[i];

    for (int i = 0; i < n; i++)
        cin >> deadline[i];

    maxActivities(n, duration, deadline);

    return 0;
}
