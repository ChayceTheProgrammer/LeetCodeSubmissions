#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using std::vector;
using std::max;
using std::min;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int x = nums1.size();
        int y = nums2.size();
        
        int low = 0;
        int high = x;
        
        while (low <= high) {
            int partitionX = (low + high) / 2;
            int partitionY = (x + y + 1) / 2 - partitionX;
            
            int maxX = (partitionX == 0) ? std::numeric_limits<int>::min() : nums1[partitionX - 1];
            int maxY = (partitionY == 0) ? std::numeric_limits<int>::min() : nums2[partitionY - 1];
            
            int minX = (partitionX == x) ? std::numeric_limits<int>::max() : nums1[partitionX];
            int minY = (partitionY == y) ? std::numeric_limits<int>::max() : nums2[partitionY];
            
            if (maxX <= minY && maxY <= minX) {
                // We have partitioned the array at the correct place
                if ((x + y) % 2 == 0) {
                    return (double)(max(maxX, maxY) + min(minX, minY)) / 2;
                } else {
                    return (double)max(maxX, maxY);
                }
            } else if (maxX > minY) {
                // Move towards the left in nums1
                high = partitionX - 1;
            } else {
                // Move towards the right in nums1
                low = partitionX + 1;
            }
        }
        
        // If the input arrays are not sorted correctly, though this should not happen by problem constraints
        throw std::invalid_argument("Input arrays are not sorted.");
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    std::cout << "Median of nums1 and nums2: " << sol.findMedianSortedArrays(nums1, nums2) << std::endl;

    /*
    // Example 2
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    std::cout << "Median of nums1 and nums2: " << sol.findMedianSortedArrays(nums1, nums2) << std::endl;

    // Example 3
    vector<int> nums1 = {0, 0};
    vector<int> nums2 = {0, 0};
    std::cout << "Median of nums1 and nums2: " << sol.findMedianSortedArrays(nums1, nums2) << std::endl;

    // Example 4
    vector<int> nums1 = {};
    vector<int> nums2 = {1};
    std::cout << "Median of nums1 and nums2: " << sol.findMedianSortedArrays(nums1, nums2) << std::endl;

    // Example 5
    vector<int> nums1 = {2};
    vector<int> nums2 = {};
    std::cout << "Median of nums1 and nums2: " << sol.findMedianSortedArrays(nums1, nums2) << std::endl;
    */

    return 0;
}
