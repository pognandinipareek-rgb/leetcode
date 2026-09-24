#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::string multiply(std::string num1, std::string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int m = num1.size();
        int n = num2.size();
        std::vector<int> result(m + n, 0);

        // Reverse iterate through num1 and num2
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + result[i + j + 1]; // Add to the current position

                result[i + j + 1] = sum % 10; // Store the unit place
                result[i + j] += sum / 10; // Carry over to the next position
            }
        }

        // Build the result string
        std::string product;
        for (int num : result) {
            if (!(product.empty() && num == 0)) { // Skip leading zeros
                product.push_back(num + '0');
            }
        }

        return product.empty() ? "0" : product;
    }
};

