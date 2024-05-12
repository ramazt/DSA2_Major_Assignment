#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>  

// Define a struct uniquely named to avoid any conflicts.
struct MyPair {
    int first;
    int second;
};

// Comparator to sort pairs based on the second element.
bool comparePairs(const MyPair& a, const MyPair& b) {
    return a.second < b.second;
}

int maxChainLen(std::vector<MyPair>& pairs) {
    std::sort(pairs.begin(), pairs.end(), comparePairs); // Sort pairs by their second elements

    int count = 0;  // Initialize count of chain length
    int last = INT_MIN;  // Initialize last to the smallest possible integer

    for (const auto& pair : pairs) {
        if (pair.first > last) {  // If the current pair can be chained
            last = pair.second;  // Update last to the second element of the current pair
            count++;  // Increase count of chain length
        }
    }

    return count;  // Returns the length of the longest chain found
}

int main() {
    std::vector<MyPair> pairs1 = {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90}};
    std::vector<MyPair> pairs2 = {{5, 10}, {1, 11}};

    std::cout << "Input: {5 24, 39 60, 15 28, 27 40, 50 90}" << std::endl;
    std::cout << "Output: " << maxChainLen(pairs1) << std::endl;

    std::cout << "Input: {5 10, 1 11}" << std::endl;
    std::cout << "Output: " << maxChainLen(pairs2) << std::endl;

    return 0;
}

