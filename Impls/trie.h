#ifndef CTCI_IMPLS_TRIE_H_
#define CTCI_IMPLS_TRIE_H_
#include <string>
#include <cctype>
#include <cassert>

// A simple trie implementation: assume string only contain ASCII's upper case letters.
class TrieNode
{
public:
    bool IsTerminated = false;  
    int count_ = 0; // number of non-empty nodes.
    TrieNode *nodes_[26] = {};
    int value;
};
class Trie
{
private:
    TrieNode root_;
    inline int ToIndex(char c)
    {
        return c - 'A';
    }
    bool Delete(const std::string &key, bool is_terminated_node)
    {
        auto np = FindNode(key.substr(0, key.size() - 1)); // find the prefix node.
        auto idx = ToIndex(key.at(key.size() - 1));
        if (np == nullptr ||                                        //  not found.
            np->nodes_[idx] == nullptr ||                           // key not present.
            (is_terminated_node && !np->nodes_[idx]->IsTerminated)) // key present but not terminated at key.
        {
            return false;
        }
        if (is_terminated_node)
        {
            np->nodes_[idx]->IsTerminated = false;
        }
        if (IsEmptyNode(np->nodes_[idx]))
        {
            delete np->nodes_[idx];
            np->nodes_[idx] = nullptr;
            np->count_--;
            if (IsEmptyNode(np))
            {
                assert(Delete(key.substr(0, key.size() - 1), false));
            }
        }
        return true;
    }
    TrieNode *FindNode(const std::string &key)
    {
        auto np = &root_;
        for (auto c : key)
        {
            np = np->nodes_[ToIndex(c)];
            if (np == nullptr)
            {
                return nullptr;
            }
        }
        return np;
    }
    inline bool IsEmptyNode(TrieNode *np)
    {
        return np->count_ == 0 && !np->IsTerminated;
    }

public:
    Trie() { root_.IsTerminated = true; }
    void Insert(const std::string &key, int value)
    {
        assert(key.size() != 0);
        auto np = &root_;
        for (auto c : key)
        {
            auto &next_np = np->nodes_[ToIndex(c)];
            if (next_np == nullptr)
            {
                next_np = new TrieNode;
                np->count_++;
            }
            np = next_np;
        }
        np->value = value;
        np->IsTerminated = true;
        return;
    }
    bool Find(const std::string &key, int &value)
    {
        assert(key.size() != 0);
        auto np = FindNode(key);
        if (np == nullptr)
        {
            return false;
        }
        value = np->value;
        return true;
    }
    bool Delete(const std::string &key)
    {
        assert(key.size() != 0);
        return Delete(key, true);
    }
};

#endif