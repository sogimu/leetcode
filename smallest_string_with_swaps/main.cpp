#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
   string smallestStringWithSwaps(string s, const vector<vector<int>>& pairs)
   {
      string result = s;
      auto pairs_copy = pairs;
      do
      {
         auto edited_s = s;
         for (const auto& pair : pairs_copy)
         {
            std::swap(edited_s[pair[0]], edited_s[pair[1]]);
            std::cout << "Swap s[" << pair[0] << "] and s[" << pair[1] << "], s = \"" << edited_s << "\"" << std::endl;
         }
         if( edited_s < s )
         {
            result = edited_s;
         }
      }
      while( std::prev_permutation(std::begin(pairs_copy), std::end(pairs_copy)) );

      return result;
   }
};

void bar(std::vector<int> s, int index, const std::vector<int>& base)
{
   auto tmp = s;
   for( int i = 0; i < 3; ++i )
   {
      tmp.emplace_back(base[index]);

   }
}

void foo(std::vector<int> s)
{

   for (const auto& cA : s)
   {
      for (const auto& cB : s)
      {
         std::vector
      }

   }
}

int main()
{
   Solution solution;

//   std::cout << (solution.smallestStringWithSwaps("dcab", {{0,3}, {1,2}}) == "bacd") << std::endl;
//   std::cout << (solution.smallestStringWithSwaps("dcab", {{0,3}, {1,2}, {0,2}}) == "abcd") << std::endl;


   return 0;
}
