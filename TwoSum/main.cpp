#include <iostream>
#include <vector>
#include <unordered_map>


// Helper lambda function to print key-value pairs
auto print_key_value = [](const auto& key, const auto& value)
{
    std::cout << "Key:[" << key << "] Value:[" << value << "]\n";
};

//O(n)
std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    // To store the number and its index
    std::unordered_map<int, int> num_map;  
    
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];

        if (num_map.find(complement) != num_map.end()) {
            return {num_map[complement], i};
        }
        num_map[nums[i]] = i;
    }
    // This return statement will never be reached because there is exactly one solution
    return {};
}

//O(n^2)
//Brute Force
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        int n = nums.size();

        //1st element to second to last
        for (int i = 0; i < n - 1; i++) {
            
            //2nd element to last (This spans all possible elements)
            for (int j = i + 1; j < n; j++) {

                //checks if elements equal target
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {}; // No solution found
    }
};



int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> result = twoSum(nums, target);
    
    std::cout << "Indices: ";
    for (int index : result) {
        std::cout << index << " ";
    }
    std::cout << std::endl;

    return 0;
}
