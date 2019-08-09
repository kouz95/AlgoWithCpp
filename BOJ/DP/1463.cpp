#include <iostream>

using namespace std;

int main()
{
    int n ;
    
    cin >> n ;
    
    int dp[1000001];
    
    
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 4 ; i <= n ; i ++)
    {
        int tmp = 0;
        if (i%3 == 0)
        {
            if (!tmp || tmp > dp[i/3] + 1)
                tmp = dp[i/3] + 1;
        }
        if (i%2 == 0)
        {
            if (!tmp || tmp > dp[i/2] + 1)
                tmp = dp[i/2] + 1;
        }
        if (!tmp || tmp > dp[i-1] +1)
            tmp = dp[i-1] + 1;
        
        dp[i]= tmp;
    }
    cout << dp[n];
}
