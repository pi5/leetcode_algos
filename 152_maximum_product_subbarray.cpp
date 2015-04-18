/*
 *Find the contiguous subarray within an array (containing at least one number) which has the largest product.
 *
 *For example, given the array [2,3,-2,4],
 *the contiguous subarray [2,3] has the largest product = 6.
 *
 */

#include <iostream>
#include <vector>
using namespace std;



int maxProduct(vector<int>& nums) {

    if (nums.size() == 0) return 0;

    int max = 1, 
        curr_positive = 1,
        curr_negative = 1;

    for(int i = 0; i < nums.size(); i++) {
        cout << curr_positive << " " << curr_negative  << " " << max << endl;
        if(nums[i] == 0) {
            curr_positive = 1;
            curr_negative = 1;    
        }   
        else if (nums[i] > 0) {
            curr_positive *= nums[i];
            curr_negative *= nums[i];
        }
        else {
            curr_negative *= nums[i];    
            if(curr_negative > 0) {
                curr_positive = curr_negative;    
            }
        }

        if(curr_negative > max) {
            max = curr_positive;    
        }
    }
    return max;
}


int main() {
    int arr[] = {2,3,-2,4};
    int len = sizeof(arr)/sizeof(arr[0]);
    vector<int> v (arr, arr+len);

    cout << endl;
    for(int i = 0; i < v.size(); i++) cout << v[i] << endl;
    cout << endl;
    cout << maxProduct(v) << endl;
}
