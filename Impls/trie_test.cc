#include <iostream>
#include "trie.h"

int main(void)
{
    Trie t;
    t.Insert("MANY", 1);
    t.Insert("MAN", 2);
    t.Insert("MY", 3);
    t.Insert("LIE", 4);
    t.Insert("A", 5);
    int v;
    assert(t.Find("MANY", v) && v == 1);
    assert(t.Delete("MANY"));
    assert(t.Find("MAN", v) && v == 2);
    assert(t.Delete("MAN"));
    assert(t.Find("MY", v) && v == 3);
    assert(t.Delete("MY"));
    assert(t.Find("LIE", v) && v == 4);
    assert(t.Delete("LIE"));
    assert(t.Find("A", v) && v == 5);
    assert(t.Delete("A"));
}