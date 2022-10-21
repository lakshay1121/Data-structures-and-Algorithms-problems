#include <bits/stdc++.h>
using namespace std;

int fibo_using_memoization(int n, vector<int> &dp)
{

    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = fibo_using_memoization(n - 1, dp) + fibo_using_memoization(n - 2, dp);
}
int main()
{
    int n;
    cin >> n;

    vector<int> dp(n + 1, -1);

    cout << fibo_using_memoization(n, dp);
    return 0;
}
