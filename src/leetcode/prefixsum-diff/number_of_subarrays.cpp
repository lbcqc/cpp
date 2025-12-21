//
// Created by root on 2025/9/7.
//
// 1248. 统计「优美子数组」 https://leetcode.cn/problems/count-number-of-nice-subarrays/
// 题解：关键在于利用前缀和统计 s[0,i] 中所含的奇数个数，s[i] = s[i-1]+nums[i]&1。注意 s[i]有
// k+x个奇数，那么我们需要找有 x 个奇数的前 子序列个数是多少， 假设 s[j] = x，那么 j->i 的子序列个数为 s[i]-s[j] = k+x-x
// = k，我们只需要找到有多少个这样的 j 即可。 技巧1：前缀和，从 1 开始，相比从 0 开始更方便处理边界值；
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int numberOfSubarrays(vector<int>& nums, int k) {
    if (nums.empty() || nums.size() < k) {
      return 0;
    }
    const int len = static_cast<int>(nums.size());
    vector<int> prefix_sum(len + 1, 0);
    prefix_sum[0] = 0;
    for (int i = 1; i <= len; i++) {
      prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1] & 1;
    }
    vector<int> count(len + 1, 0);  // 注意：前缀和大小不可能超过 len(所有数都是奇数)
    count[prefix_sum[0]]++;  // 注意：这里表示只包含自身的也算 1，因为 prefix_sum[0] 就是初始的 -1
                             // 下标边界，不包含任何值
    int ans = 0;
    for (int i = 1; i <= len; i++) {
      if (prefix_sum[i] - k >= 0) {
        ans += count[prefix_sum[i] - k];
      }
      count[prefix_sum[i]]++;
    }
    return ans;
  }
};