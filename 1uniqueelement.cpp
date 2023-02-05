#include<iostream>
#include<vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int result=0;
        for(int i=0; i<nums.size(); i++)
    result= result^nums[i];
        return result;
}
int main()
{
vector <int> v={2,2,1,1,3,3,5};
int size=7;
cout<<singleNumber(v);
return 0;
}