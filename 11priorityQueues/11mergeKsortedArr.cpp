#include<iostream>
#include<queue>

using namespace std;

vector<int> mergeKsortedArr(vector<vector<int>*> v)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<v.size(); i++)
    {
        for(int j=0; j<v[i]->size(); j++)
        {
            pq.push(v[i]->at(j));
        }
    }


vector <int> ans;
    while (!pq.empty())
    {
        /* code */
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
int main()
{
 int k;
    cin >> k;
    vector<vector<int> *> input;
    for (int j = 1; j <= k; j++) {
        int size;
        cin >> size;
        vector<int> *current = new vector<int>;
        for (int i = 0; i < size; i++) {
            int a;
            cin >> a;
            current->push_back(a);
        }
        input.push_back(current);
    }
    vector<int> output = mergeKsortedArr(input);
    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }
    return 0;

}