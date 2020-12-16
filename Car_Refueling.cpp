#include <bits/stdc++.h>
using namespace std;

int func(vector<vector<int>> &st, int n, int target, int fuel)
{
    int curr = 0;
    priority_queue<int> pq;
    curr += fuel;
    int i = 0, count = 0;
    while (target > curr)
    {
        count++;
        while (i < n && st[i][0] <= curr)
        {
            pq.push(st[i][1]);
            i++;
        }
        if (pq.empty())
        {
            break;
        }
        curr += pq.top();
        pq.pop();
    }
    return curr >= target ? count : -1;
}

int main()
{
    int n, target, fuel;
    cin >> n >> target >> fuel;
    vector<vector<int>> st(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> st[i][j];
        }
    }
    cout << func(st, n, target, fuel);
    return 0;
}