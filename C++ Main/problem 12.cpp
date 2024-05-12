#include <iostream>
#include <vector>

using namespace std;

int numberSequence(int m, int n) {
   
    vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));

    for (int j = 1; j <= m; j++)
        dp[1][j] = 1;

   
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= j / 2; k++) {
                dp[i][j] += dp[i - 1][k];
            }
        }
    }

    int total = 0;
    for (int j = 1; j <= m; j++)
        total += dp[n][j];

    return total;
}

int main() {
    
    int m1 = 10, n1 = 4;
    cout << "1 Output: " << numberSequence(m1, n1) << endl;

    int m2 = 5, n2 = 2;
    cout << "2 Output: " << numberSequence(m2, n2) << endl;

return 0;
}

