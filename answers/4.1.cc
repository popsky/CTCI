#include <set>
#include <queue>
#include <vector>
class TreeNode
{
public:
    bool is_marked_ = false;
    std::vector<TreeNode *> adjacent_;
};

bool RouteBetweenTowNodes(TreeNode *src, TreeNode *dest)
{
    std::queue<TreeNode *> q1, q2;
    std::set<TreeNode *> s1, s2;
    q1.push(src);
    src->is_marked_ = true;
    q2.push(dest);
    dest->is_marked_ = true;
    while (!q1.empty() || !q2.empty())
    {
        if (!q1.empty())
        {
            auto n = q1.front();
            q1.pop();
            if (s2.count(n) > 0)
            {
                return true;
            }
            for (auto an : n->adjacent_)
            {
                if (!an->is_marked_)
                    q1.push(an);
            }
        }

        if (!q2.empty())
        {
            auto n = q2.front();
            q2.pop();
            if (s1.count(n) > 0)
            {
                return true;
            }
            for (auto an : n->adjacent_)
            {
                if (!an->is_marked_)
                    q2.push(an);
            }
        }
    }
    return false;
}