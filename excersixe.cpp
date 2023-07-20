#include <iostream>
#include <vector>

using namespace std;

int countSpecialSubarrays(vector<int>& arr) {
    int count = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        int min_element = arr[i];
        int max_min = arr[i];
        long long product=1;


        for (int j = i; j >= 0; j--) {
            min_element = min(min_element, arr[j]);
            max_min = max(max_min, arr[j]);
            product= min_element * max_min;
            int length = i - j + 1;

            if (product % length == 0) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    // Example usage
    vector<int> arr = {0,1,3};
    int specialSubarrays = countSpecialSubarrays(arr);
    cout << "Number of special subarrays: " << specialSubarrays << endl;

    return 0;
}