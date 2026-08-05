#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    // =====================================================
    // Approach 1: Using Extra Array (Visited Array)
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    // =====================================================

    int missingNumber(vector<int>& nums) {

        int n = nums.size();

        vector<bool> flag(n + 1, false);

        for (int i = 0; i < n; i++) {
            flag[nums[i]] = true;
        }

        for (int i = 0; i <= n; i++) {
            if (!flag[i])
                return i;
        }

        return -1;
    }


    // =====================================================
    // Approach 2: Sorting
    // Time Complexity: O(n log n)
    // Space Complexity: O(1)
    // =====================================================

    /*
    int missingNumber(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i != nums[i])
                return i;
        }

        return n;
    }
    */


    // =====================================================
    // Approach 3: Brute Force
    // Time Complexity: O(n²)
    // Space Complexity: O(1)
    // =====================================================

    /*
    int missingNumber(vector<int>& nums) {

        int n = nums.size();

        for (int i = 0; i <= n; i++) {

            bool found = false;

            for (int j = 0; j < n; j++) {

                if (nums[j] == i) {
                    found = true;
                    break;
                }
            }

            if (!found)
                return i;
        }

        return -1;
    }
    */
};