#ifndef CTCI_IMPLS_TREE_DFS_H_
#define CTCI_IMPLS_TREE_DFS_H_
#include <vector>
#include <iostream>
#include <queue>
#include <set>
class TreeNode
{
public:
    std::vector<TreeNode *> adjacent_;
    int value_;
    bool is_marked_ = false;
    bool is_visited_ = false;
};
void Visit(TreeNode *n)
{
    n->is_visited_ = true;
    std::cout << "visit node :" << n->value_ << " > ";
}
void DFS(TreeNode *np, void visit(TreeNode *))
{
    if (np == nullptr)
    {
        return;
    }
    visit(np);
    for (auto p : np->adjacent_)
    {
        if (!p->is_visited_)
        {
            DFS(p, visit);
        }
    }
    return;
}
void BFS(TreeNode *np, void visit(TreeNode *))
{
    std::queue<TreeNode *> queue;
    queue.push(np);
    np->is_marked_ = true;
    while (!queue.empty())
    {
        auto p = queue.front();
        queue.pop();
        visit(p);
        for (auto ap : p->adjacent_)
        {
            if (!ap->is_marked_)
            {
                queue.push(ap);
                ap->is_marked_ = true;
            }
        }
    }
}
void BidirectionalSearch(TreeNode *src, TreeNode *dest)
{
    std::set<TreeNode *> s1, s2;
    std::queue<TreeNode *> q1, q2;
    q1.push(src);
    src->is_marked_ = true;
    q2.push(dest);
    dest->is_marked_ = true;
    while (!q1.empty() && !q2.empty())
    {
        auto n = q1.front();
        q1.pop();
        if (s2.count(n) > 0)
        {
            return;
        }
        s1.insert(n);

        for (auto nn : n->adjacent_)
        {
            if (!nn->is_marked_)
            {
                q1.push(nn);
            }
        }
        n = q2.front();
        q2.pop();
        if (s1.count(n) > 0)
        {
            return;
        }
        s2.insert(n);
    }
}
#endif