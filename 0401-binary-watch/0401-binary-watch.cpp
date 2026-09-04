#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;

        // Loop through all possible hour values (0-11)
        for (int hour = 0; hour < 12; ++hour) {
            // Loop through all possible minute values (0-59)
            for (int minute = 0; minute < 60; ++minute) {
                // Count the number of bits that are on in hour and minute
                if (countBits(hour) + countBits(minute) == turnedOn) {
                    // Format the time correctly
                    string time = to_string(hour) + ":" + (minute < 10 ? "0" : "") + to_string(minute);
                    result.push_back(time);
                }
            }
        }

        // Sort the result in descending order
        sort(result.rbegin(), result.rend());

        return result;
    }

private:
    // Helper function to count the number of bits set to 1
    int countBits(int num) {
        return __builtin_popcount(num); // GCC/Clang specific
    }
};



