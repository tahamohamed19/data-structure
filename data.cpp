#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> numToIndex;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (numToIndex.find(complement) != numToIndex.end()) {
                return {numToIndex[complement], i};
            }
            numToIndex[nums[i]] = i;
        }
       
        return {};
    }
};




#include <cstdint>  
class Solution {
public:
    bool isPalindrome(int x) {
     
        if (x < 0) {
            return false;
        }
        
      
        if (x == 0) {
            return true;
        }
        
       
        long long reversed = 0;
        int original = x;
        while (x > 0) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }
        
        return reversed == original;
    }
};
