#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void merge(vector<int>& arr, int m, vector<int>& arr2, int n)
    {
        int i=m-1;
        int j=n-1;
        int k=m+n-1;
        while( i>= 0 && j>=0 )
        {
            if( arr[i] < arr2[j] )
            {
                arr[k--] = arr2[j--];
            }
            else
            {
                arr[k--] = arr[i--];
            }
        }
        while( j >= 0 )
        {
            arr[k--] = arr2[j--];
        }
    }
};


int main()
{
    Solution solution;

    std::vector<int> v0 {1,2,3,0,0,0};
    std::vector<int> v1 {2,5,6};
    solution.merge(v0, 3, v1, 3);
    std::vector<int> expected0 {1,2,2,3,5,6};
    std::cout << (v0 == expected0) << std::endl;

    std::vector<int> v2 {1};
    std::vector<int> v3 {};
    solution.merge(v2, 1, v3, 0);
    std::vector<int> expected1 {1};
    std::cout << (v2 == expected1) << std::endl;

    std::vector<int> v4 {0};
    std::vector<int> v5 {1};
    solution.merge(v4, 0, v5, 1);
    std::vector<int> expected2 {1};
    std::cout << (v4 == expected2) << std::endl;

    return 0;
}
