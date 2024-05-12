#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pair {
    int first;
    int second;
};

// Comparator to sort pairs based on the first element
bool comparePairs(const Pair& a, const Pair& b) {
    return a.first < b.first;
}

int maxChainLen(vector<Pair>& pairs) {
    sort(pairs.begin(), pairs.end(), comparePairs); // Sort pairs by their first elements

    int n = pairs.size();
    vector<int> dp(n, 1);  // DP array initialized to 1 since the smallest chain includes the pair itself

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (pairs[j].second < pairs[i].first) {
                dp[i] = max(dp[i], dp[j] + 1);  // Maximize the chain length using the j-th pair
            }
        }
    }

    return *max_element(dp.begin(), dp.end());  // Return the maximum value in dp array
}

int main() {
    vector<Pair> pairs1 = {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90}};
    vector<Pair> pairs2 = {{5, 10}, {1, 11}};

    cout << "Input: {5 24, 39 60, 15 28, 27 40, 50 90}" << endl;
    cout << "Output: " << maxChainLen(pairs1) << endl;

    cout << "Input: {5 10, 1 11}" << endl;
    cout << "Output: " << maxChainLen(pairs2) << endl;

    return 0;
}

