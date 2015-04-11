/*    Leetcode #42
 *    Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
 *
 *    For example, 
 *    Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 */

#include<iostream>
using namespace std;

int trap(int A[], int n) {
    int water = 0;

    /* Store all max after an element */
    int max_after[n];
    int max = INT_MIN;
    for (int i = n-1; i >=0 ; i--) {
        if(A[i] > max){
            max = A[i];    
        }           
        max_after[i] = max;
    }

    /* We iterate through the array and keep account of
     * max encountered till current position
     */
    max = INT_MIN;
    for(int i = 0; i < n; i++) {
        if (A[i] > max) max = A[i];
        int level = min(max_after[i], max);
        //cout << i << " " << max_after[i] << " " << max << endl;
        int w = level - A[i];
        water += (w > 0 ? w : 0);
    }

    return water;
}


int main() {

    int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int len = (sizeof(arr)/sizeof(arr[0]));

    cout << trap(arr, len) << endl;
}
