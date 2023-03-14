#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

//class Solution {
//public:
//   bool isPalidrome(const string& s, size_t from, size_t to)
//   {
//      bool result = true;
//
//      std::string word(s.begin()+from, s.begin()+to);
//
//      auto size = to - from;
//      auto halfOfSize = size / 2;
//      for (size_t i=from; i<halfOfSize; ++i)
//      {
//         if (s[i] != s[size-1-i])
//         {
//            result = false;
//            break;
//         }
//      }
//      return result;
//   }
//
//   string longestPalindrome(string s)
//   {
//      string result;
//
//      for (size_t i=0; i<s.size(); ++i)
//      {
//         for (size_t j=i; j<s.size(); ++j)
//         {
////            std::string word(s.begin()+i, s.begin()+j+1);
////            std::cout << word << std::endl;
//
//            if ( isPalidrome(s, i, j+1) )
//            {
//               if (j+1-i > result.size())
//               {
//                  std::string word(s.begin()+i, s.begin()+j+1);
//                  result.swap(word);
//               }
//            }
//         }
//      }
//
//      return result;
//   }
//};

class Solution {
public:
   bool isPalidrome(const string& s)
   {
      bool result = true;

      if (s.size() == 1)
      {
         return result;
      }

      auto size = s.size();
      auto halfSize = s.size()/2;

      for (size_t i=0; i<halfSize; ++i)
      {
         if (s[i] != s[size-1-i])
         {
            result = false;
            break;
         }
      }
      return result;
   }

   string longestPalindrome(string s)
   {
      string result;

      if (s.size() == 1)
      {
         return s;
      }

      for (size_t i=0; i<s.size(); ++i)
      {
         for (size_t j=s.size()-1; j>i; --j)
         {
            std::string word(s.begin()+i, s.begin()+j+1);

            if ( isPalidrome(word))
            {
               if (word.size() > result.size())
               {
                  result.swap(word);
               }
            }
         }
      }

      return result;
   }
};

int main() {
   Solution solution;
   std::cout << (solution.longestPalindrome("ac") == "a") << std::endl;
   std::cout << (solution.longestPalindrome("a") == "a") << std::endl;
   std::cout << (solution.longestPalindrome("babad") == "bab") << std::endl;
   std::cout << (solution.longestPalindrome("cbbd") == "bb") << std::endl;
//   std::cout << (solution.longestPalindrome("jhgtrclvzumufurdemsogfkpzcwgyepdwucnxrsubrxadnenhvjyglxnhowncsubvdtftccomjufwhjupcuuvelblcdnuchuppqpcujernplvmombpdttfjowcujvxknzbwmdedjydxvwykbbamfnsyzcozlixdgoliddoejurusnrcdbqkfdxsoxxzlhgyiprujvvwgqlzredkwahexewlnvqcwfyahjpeiucnhsdhnxtgizgpqphunlgikogmsffexaeftzhblpdxrxgsmeascmqngmwbotycbjmwrngemxpfakrwcdndanouyhnnrygvntrhcuxgvpgjafijlrewfhqrguwhdepwlxvrakyqgstoyruyzohlvvdhvqmzdsnbtlwctetwyrhhktkhhobsojiyuydknvtxmjewvssegrtmshxuvzcbrabntjqulxkjazrsgbpqnrsxqflvbvzywzetrmoydodrrhnhdzlajzvnkrcylkfmsdode") == "bb") << std::endl;
   return 0;
}