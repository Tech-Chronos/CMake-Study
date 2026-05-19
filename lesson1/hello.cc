#include <iostream>
#include <vector>
#include <random>

void _QuickSort(std::vector<int>& nums, int l, int r)
{
    if (l >= r) return;
    // 得到一个随机的索引
    int index = l + (rand() % (r - l + 1));
    int pivot = nums[index];

    int left = l - 1, right = r + 1, cur = l;
    // [l ,left] [left + 1, right - 1] [right, r]
    while (cur < right)
    {
        if (nums[cur] < pivot) 
            std::swap(nums[++left], nums[cur++]);
        else if (nums[cur] > pivot) 
            std::swap(nums[--right], nums[cur]);
        else 
            ++cur;
    }

    _QuickSort(nums, l, left);
    _QuickSort(nums, right, r);
}

void QuickSort(std::vector<int>& nums)
{
    _QuickSort(nums, 0, nums.size() - 1);
}

int main()
{
    srand(time(nullptr));
    // std::cout << "hello cmake ..." << std::endl;
    std::vector<int> v { 10,9,8,7,6,5,4,3,2,1,0 };
    QuickSort(v);

    for (auto& num : v)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";
    return 0;
}