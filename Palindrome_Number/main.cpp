#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
   bool isPalindrome(int x) {
      if (x < 0)
      {
         return false;
      }

      std::vector<int> decomposition;

      int tmp = x;
      while(tmp > 0)
      {
         decomposition.push_back(tmp % 10);
         tmp = tmp / 10;
      }

      bool result = true;

      size_t size = decomposition.size();
      for (size_t i=0; i<decomposition.size()/2; ++i)
      {
         auto a = decomposition[i];
         auto b = decomposition[size-1-i];
         if (a != b)
         {
            result = false;
            break;
         }
      }

      return result;
   }
};

int main() {
   Solution solution;
   std::cout << (solution.isPalindrome(123321) == true) << std::endl;
   std::cout << (solution.isPalindrome(121) == true) << std::endl;
   std::cout << (solution.isPalindrome(123) == false) << std::endl;
   return 0;
}