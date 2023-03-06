#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode()
         : val(0)
         , left(nullptr)
         , right(nullptr)
     {
     }

     TreeNode(int x)
         : val(x)
         , left(nullptr)
         , right(nullptr)
     {
     }

     TreeNode(int x, TreeNode *left, TreeNode *right)
         : val(x)
         , left(left)
         , right(right)
     {
     }
};

class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        if( !root )
            return {};

        auto result = inorderTraversal(root->left);
        result.emplace_back( root->val );
        const auto& right_nodes = inorderTraversal(root->right);
        std::copy(begin(right_nodes), end(right_nodes), std::back_inserter(result));
        return result;
    }
};

class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        std::vector<int> result;

        TreeNode* current = root;

        std::stack<TreeNode*> stack;

        while( current || !stack.empty() )
        {
            while( current )
            {
                stack.emplace(current);
                current = current->left;
            }

            /*
             * Now current equal to nullptr. Set current to most left node
             */
            current = stack.top();
            stack.pop();

            result.emplace_back( current->val );

            current = current->right;
        }

        return result;
    }
};

int main()
{
    Solution2 s;

    TreeNode node1{1};
    TreeNode node2{2};
    TreeNode node3{3, &node1, &node2};
    std::vector<int> expected {1,3,2};
    cout << static_cast<bool>(s.inorderTraversal( &node3 ) == expected) << endl;

    return 0;
}
