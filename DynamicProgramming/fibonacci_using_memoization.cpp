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

int fibo_using_tabulation(int n, vector<int> &dp)
{

    for (int i = 2; i < n; i++)
    {

        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;

    vector<int> dp(n + 1, -1);

    cout << fibo_using_memoization(n, dp);

    cout << endl;

    cout << fibo_using_tabulation(n, dp);
    return 0;
}
