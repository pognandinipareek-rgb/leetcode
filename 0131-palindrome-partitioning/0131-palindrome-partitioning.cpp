#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to check if a string is a palindrome
    bool isPalin(string s) {
        string s2 = s; // Create a copy of the string
        reverse(s2.begin(), s2.end()); // Reverse the string
        return s == s2; // Compare original and reversed strings
    }

    // Recursive function to find all palindromic partitions
    void getAllParts(string s, vector<string>& partition, vector<vector<string>>& ans) {
        if (s.size() == 0) { // Base case: if the string is empty
            ans.push_back(partition); // Add current partition to the results
            return;
        }
        for (int i = 0; i < s.size(); i++) {
            string part = s.substr(0, i + 1); // Get the substring from 0 to i

            if (isPalin(part)) { // Check if the substring is a palindrome
                partition.push_back(part); // Add the palindrome to the current partition
                getAllParts(s.substr(i + 1), partition, ans); // Recur with the remaining substring
                partition.pop_back(); // Backtrack
            }
        }
    }

    // Main function to partition the string
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans; // To store the final result
        vector<string> partition; // To store the current partition
        getAllParts(s, partition, ans); // Start the recursive function
        return ans; // Return the result
    }
};
