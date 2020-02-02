#include "mini_heap.h"
#include <cassert>
#include <iostream>

int main(void)
{
    MiniHeap h(7);
    h.Insert(5);
    h.Insert(4);
    h.Insert(3);
    h.Insert(1);
    h.Insert(2);
    h.Insert(-1);
    h.Insert(10);
    assert(h.ExtractMini() == -1);
    assert(h.ExtractMini() == 1);
    assert(h.ExtractMini() == 2);
    assert(h.ExtractMini() == 3);
    assert(h.ExtractMini() == 4);
    assert(h.ExtractMini() == 5);
    // 10
    h.Insert(100);
    h.Insert(1);
    assert(h.ExtractMini() == 1);
    assert(h.ExtractMini() == 10);
    assert(h.ExtractMini() == 100);
    try
    {
        h.ExtractMini();
    }
    catch (std::out_of_range &e)
    {
        std::cout << e.what() << std::endl;
    }
}