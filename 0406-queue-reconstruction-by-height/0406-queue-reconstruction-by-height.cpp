#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // Step 1: Sort the people
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
            // Sort by height in descending order and then by k in ascending order
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });

        // Step 2: Reconstruct the queue
        vector<vector<int>> queue;
        for (const auto& person : people) {
            queue.insert(queue.begin() + person[1], person);
        }

        return queue;
    }
};

