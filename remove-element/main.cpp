#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int number_of_deleted = 0;
        for(int i=0; i<nums.size()-number_of_deleted;  )
        {
            if(nums[i] == val)
            {
                for(int j=i; j<nums.size()-number_of_deleted-1; ++j)
                {
                    std::swap(nums[j], nums[j+1]);
                }
                ++number_of_deleted;
            }
            else
            {
                ++i;
            }
        }
        return nums.size() - number_of_deleted;
    }
};

int main()
{
    Solution solution;

    std::vector<int> v1 {0,1,2,2,3,0,4,2};
    std::cout << static_cast<bool>(solution.removeElement(v1, 2) == 5) << std::endl;

    std::vector<int> v0 {3,2,2,3};
    std::cout << static_cast<bool>(solution.removeElement(v0, 3) == 2) << std::endl;

    return 0;
}
