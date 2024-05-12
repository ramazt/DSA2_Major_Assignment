#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to check if a part of the string can be a valid segment of an IP address.
bool isValid(const string& s) {
    if (s.empty() || s.size() > 3 || (s.size() > 1 && s[0] == '0'))  // "0" is valid, "01" is not.
        return false;
    int num = stoi(s);
    return num <= 255 && num >= 0;
}

// Helper function to recursively generate IPs
void generateIPs(vector<string>& result, string s, int start, int parts, string currentIP) {
    if (parts == 4 && start == s.size()) {  // If 4 parts are done and we've used all characters
        result.push_back(currentIP.substr(0, currentIP.length() - 1));  // Remove the last dot
        return;
    }

    if (parts == 4 || start == s.size())  // Base case: if parts or string length is exceeded
        return;

    for (int len = 1; len <= 3 && start + len <= s.size(); len++) {  // Try all lengths (1 to 3)
        string part = s.substr(start, len);
        if (isValid(part)) {
            generateIPs(result, s, start + len, parts + 1, currentIP + part + '.');  // Recur with the next part
        }
    }
}

// Main function to initiate IP generation
vector<string> restoreIpAddresses(string s) {
    vector<string> result;
    generateIPs(result, s, 0, 0, "");
    return result;
}

int main() {
    string s = "1111";
    vector<string> validIPs = restoreIpAddresses(s);

    if (validIPs.empty()) {
        cout << "-1" << endl;
    } else {
        for (const string& ip : validIPs) {
            cout << ip << endl;
        }
    }

    // Test with an input that should result in "-1"
    string s2 = "55";  // Input leads to valid IP "1.1.1.1"
    vector<string> validIPs2 = restoreIpAddresses(s2);
    if (validIPs2.empty()) {
        cout << "-1" << endl;
    } else {
        for (const string& ip : validIPs2) {
            cout << ip << endl;
        }
    }

return 0;
}

