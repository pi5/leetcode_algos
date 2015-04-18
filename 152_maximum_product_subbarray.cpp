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
    bool zero = false;
    bool positive = false;
    int max = INT_MIN, 
        curr_positive = 1,
        curr_negative = 1;

    for(int i = 0; i < nums.size(); i++) {
        //cout << curr_positive << " " << curr_negative  << " " << max << endl;
        if(nums[i] == 0) {
            zero = true;
            curr_positive = 1;
            curr_negative = 1;    
        }   
        else if (nums[i] > 0) {
            positive = true;
            curr_positive *= nums[i];
            curr_negative = std::min(curr_negative*nums[i], 1);
        }
        else {
            if(curr_negative < 0) {
                positive = true;    
            }
            int temp = curr_positive;
            curr_positive = std::max(curr_negative*nums[i], 1);
            curr_negative = temp*nums[i];   
        }

        if(curr_positive > max) {
            if(nums[i] == 0 && zero) {
                max = 0; 
            }
            else
                max = curr_positive;    
        }
    }

    if (zero && !positive) return 0;
    
    return positive ? max : curr_negative;
}


int main() {
    //int arr[] = {2,3,-2,4};
    //int arr[] = {-3,-2,-4};
    int arr[] = {-2,0,-1};
    int len = sizeof(arr)/sizeof(arr[0]);
    vector<int> v (arr, arr+len);

    cout << endl;
    for(int i = 0; i < v.size(); i++) cout << v[i] << endl;
    cout << endl;
    cout << maxProduct(v) << endl;
}
