/*
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

#include<iostream>
using namespace std;

/* Recursive Solution */
int climbStairs(int n) {
    if (n < 0) return 0;
    if (n == 0) {
        return 1;    
    } 

    return climbStairs(n-1) + climbStairs(n-2);
}


/* Dynamic programming solution */
int climbStairs_dp(int n) {
    if (n <= 0) return 0;

    int memo[n];
    memo[0] = 1;
    memo[1] = 2;

    for (int i = 2; i <= n; i++) {
        memo[i] = memo[i-1] + memo[i-2];    
    }
    return memo[n-1];
}


int main() {
    int n;
    cin >> n;
    cout << climbStairs(n) << endl;    
    cout << climbStairs_dp(n) << endl;    
    
}
