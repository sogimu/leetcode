#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int last_word_counter = 0;
        bool is_accumulating = false;
        for(int i=s.size()-1; i>=0; --i)
        {
            if( s[i] == ' ' )
            {
                if( is_accumulating )
                    return last_word_counter;
            }
            else
            {
                if( !is_accumulating )
                    is_accumulating = true;
            }
            if( is_accumulating )
                ++last_word_counter;
        }
        if( is_accumulating )
            return last_word_counter;
        else
            return 0;
    }
};

int main()
{
    Solution solution;

    std::string v0 {"Hello World"};
    std::cout << static_cast<bool>(solution.lengthOfLastWord(v0) == 5) << std::endl;

    std::string v1 {"   fly me   to   the moon  "};
    std::cout << static_cast<bool>(solution.lengthOfLastWord(v1) == 4) << std::endl;

    std::string v2 {"luffy is still joyboy"};
    std::cout << static_cast<bool>(solution.lengthOfLastWord(v2) == 6) << std::endl;

    std::string v3 {"a"};
    std::cout << static_cast<bool>(solution.lengthOfLastWord(v3) == 1) << std::endl;

    return 0;
}
