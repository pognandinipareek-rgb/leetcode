#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    set<vector<int>> s; // To store unique combinations

    void getAllCombinations(vector<int>& candidates, int indx, int target, vector<vector<int>>& ans, vector<int> comb) {
        if (indx == candidates.size() || target < 0) {
            return; // Base case: out of bounds or target negative
        }
        if (target == 0) {
            if (s.find(comb) == s.end()) { // Check for uniqueness
                ans.push_back(comb); // Add valid combination to results
                s.insert(comb); // Store it in the set
            }
            return;
        }

        // Include current candidate (single)
        comb.push_back(candidates[indx]);
        getAllCombinations(candidates, indx + 1, target - candidates[indx], ans, comb);
        
        // Include current candidate (multiple)
        getAllCombinations(candidates, indx, target - candidates[indx], ans, comb);
        
        // Backtrack
        comb.pop_back();

        // Exclude current candidate
        getAllCombinations(candidates, indx + 1, target, ans, comb);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans; // To store results
        vector<int> comb; // Current combination
        getAllCombinations(candidates, 0, target, ans, comb); // Start recursion
        return ans; // Return the result
    }
};
