#include <iostream>
#include <queue>

using namespace std;

vector<int> kMinelements(int *a, int size, int k)
{

    vector<int> finalans;

    priority_queue<int, vector<int>, greater<int>> ans;
    for (int i = 0; i < k; i++)
    {
        ans.push(a[i]);
    }

    for (int i = k; i < size; i++)
    {
        if (a[i] > ans.top())
        {
            ans.push(a[i]);
            ans.pop();
        }
    }

    while (!ans.empty())
    {
        finalans.push_back(ans.top());
        ans.pop();
    }

    return finalans;
}

int main()
{

    int a[] = {2, 12, 9, 16, 10, 5, 3, 20, 25, 11, 1, 8, 6};
    int size = 13;
    int k = 4;

    vector<int> output = kMinelements(a, size, k);

    for (auto value : output)
    {
        cout << value << " ";
    }
    return 0;
}