#ifndef CTCI_IMPLS_MINI_HEAP_H_
#define CTCI_IMPLS_MINI_HEAP_H_
#include <vector>
#include <stdexcept>
class MiniHeap
{
private:
    std::vector<int> data_;
    size_t size_;

    void Swap(size_t idx1, size_t idx2)
    {
        auto temp = data_[idx1];
        data_[idx1] = data_[idx2];
        data_[idx2] = temp;
        return;
    }
    size_t SmallerIdx(size_t idx) // return smaller one among the node and it's childrens.
    {
        auto i = data_[idx] < data_[idx * 2] ? idx : idx * 2;
        if (idx * 2 + 1 < size_) // has right child.
        {
            i = data_[i] < data_[idx * 2 + 1] ? i : idx * 2 + 1;
        }
        return i;
    }

public:
    MiniHeap(size_t capacity) : data_(capacity + 1), size_(1) {}
    void Insert(int item)
    {
        if (size_ >= data_.size())
        {
            throw std::out_of_range("mini heap is full");
        }
        data_[size_] = item;
        auto i = size_;
        size_++;
        while (i > 1 && data_[i] < data_[i / 2])
        {
            Swap(i, i / 2);
            i = i / 2;
        }
        return;
    }
    int ExtractMini()
    {
        if (size_ <= 1)
        {
            throw std::out_of_range("mini heap is empty");
        }
        auto result = data_[1];
        Swap(1, size_ - 1);
        size_--;
        auto i = 1;
        while (2 * i < size_) // has child?
        {
            auto smaller_idx = SmallerIdx(i);
            if (smaller_idx == i) // done.
            {
                break;
            }
            Swap(i, smaller_idx);
            i = smaller_idx;
        }
        return result;
    }
};
#endif