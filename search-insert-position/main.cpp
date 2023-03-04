#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        for( int i=0; i<nums.size(); ++i)
        {
            if( target <= nums[i]  )
            {
                return i;
            }
        }
        return nums.size();
    }
};

int main()
{
    Solution solution;

    std::vector<int> v0 {1,3,5,6};
    std::cout << static_cast<bool>(solution.searchInsert(v0, 5) == 2) << std::endl;

    std::vector<int> v1 {1,3,5,6};
    std::cout << static_cast<bool>(solution.searchInsert(v1, 2) == 1) << std::endl;

    std::vector<int> v2 {1,3,5,6};
    std::cout << static_cast<bool>(solution.searchInsert(v2, 7) == 4) << std::endl;

    return 0;
}
