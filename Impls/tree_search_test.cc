#include <iostream>
#include "tree_search.h"

int main(void)
{
    TreeNode t0, t1, t2, t3, t4, t5;
    t0.value_ = 0;
    t0.adjacent_ = {&t1, &t4, &t5};
    t1.value_ = 1;
    t1.adjacent_ = {&t3, &t4};
    t2.value_ = 2;
    t2.adjacent_ = {&t1};
    t3.value_ = 3;
    t3.adjacent_ = {&t2, &t4};
    t4.value_ = 4;
    t5.value_ = 5;
    std::cout << "DFS:\n";
    DFS(&t0, Visit);
    std::cout << "\nBFS:\n";
    BFS(&t0, Visit);
    DFS(&t0, [](TreeNode *n) { n->is_masked_ = false; });
    BFS(&t0, [](TreeNode *n) { n->is_visited_ = false; });
    std::cout << "DFS:\n";
    DFS(&t0, Visit);
    std::cout << "\nBFS:\n";
    BFS(&t0, Visit);
}