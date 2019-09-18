#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    int dp[2][n+1];

    for (int i = n; i >= 1; i--) {
        for (int j = i; j <= n; j++) {
            if (i == j)
                dp[i%2][j] = 1;
            else if (j == i+1)
            {
                if (s[i-1] == s[j-1]) dp[i%2][j] = 2;
                else dp[i%2][j] = 1;
            }
            else {
                if (s[i-1] == s[j-1]) dp[i%2][j] = 2+dp[(i+1)%2][j-1];
                else dp[i%2][j] = max(dp[(i+1)%2][j], dp[i%2][j-1]);
            }
        }
    }


    cout << n-dp[1][n] << "\n";

    return 0;
}
