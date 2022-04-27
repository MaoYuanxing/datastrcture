#include <vector>

class FenwickTree
{
public:
    FenwickTree(int n) : sum_(n + 1, 0) {}

    void update(int i, int delta)
    {
        while (i < sum_.size())
        {
            sum_[i] += delta;
            i += lowbit(i);
        }
    }

    int query(int i)
    {
        int sum = 0;
        while (i > 0)
        {
            sum += sum_[i];
            i -= lowbit(i);
        }
    }

private:
    static inline int lowbit(int x) { return x & (-x); }
    std::vector<int> sum_;
}