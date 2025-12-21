# 数组系列题型

## 资料

- [极客时间-三节算法刷题课](https://u.geekbang.org/lesson/343?article=422778&utm_campaign=geektime_search&utm_content=geektime_search&utm_medium=geektime_search&utm_source=geektime_search&utm_term=geektime_search)
- [代码随想录](https://programmercarl.com/0704.%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE)

## 题目

- array
  - binary_search：[704. 二分查找](https://leetcode.cn/problems/binary-search/description/)
  - remove_duplicate: [26. 删除有序数组中的重复项](https://leetcode.cn/problems/remove-duplicates-from-sorted-array/)
  - plus_one: [66. 加一](https://leetcode.cn/problems/plus-one/description/)
- heap: 堆，优先级队列，默认为最大值堆，对应的比较函数为 less
  - max_sliding_windows: [239. 滑动窗口最大值](https://leetcode.cn/problems/sliding-window-maximum/description/)
- list
  - reverse_list: [206. 反转链表](https://leetcode.cn/problems/reverse-linked-list/)
  - k_group_reverse_list: [K 个一组翻转链表](https://leetcode.cn/problems/reverse-nodes-in-k-group/)
  - find_neighbor_value: [邻值查找](https://www.acwing.com/problem/content/description/138/)
  - linked-list-cycle：[141. 环形链表](https://leetcode.cn/problems/linked-list-cycle/description/)
  - linked-list-cycle-ii: [142. 环形链表 II](https://leetcode.cn/problems/linked-list-cycle-ii/description/)
  - merge_two_list: [21. 合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists/)
- point：双指针常用于固定一端，寻找另一端的合适位置
  - trap：[42. 接雨水](https://leetcode.cn/problems/trapping-rain-water/solutions/692342/jie-yu-shui-by-leetcode-solution-tuvc/)
  - two_sum: [1. 两数之和](https://leetcode.cn/problems/two-sum/description/)
  - two_sum_ii: [167. 两数之和 II - 输入有序数组](https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/)
  - three_sum：[15. 三数之和](https://leetcode.cn/problems/3sum/description/)
  - max_area: [11. 盛最多水的容器](https://leetcode.cn/problems/container-with-most-water/description/)
- prefixsum: 前缀和题目常出现可用 sum[l,r] = sum[0,r]-sum[0,l-1] 的题型上
  - max_sub_array：[53. 最大子数组和](https://leetcode.cn/problems/maximum-subarray/)
  - number_of_subarrays: [1248. 统计「优美子数组」](https://leetcode.cn/problems/count-number-of-nice-subarrays/)
  - range_sum_query_2d_immutable：[304. 二维区域和检索 - 矩阵不可变](https://leetcode.cn/problems/range-sum-query-2d-immutable/description/)
- queue：单调队列，先进先出
  - max_sliding_windows: [239. 滑动窗口最大值](https://leetcode.cn/problems/sliding-window-maximum/description/)
  - double_queue: [641. 设计循环双端队列](https://leetcode.cn/problems/design-circular-deque/solutions/1743694/she-ji-xun-huan-shuang-duan-dui-lie-by-l-97v0/)
- recursion：常用于子集、排列、组合、回溯等问题；递归关键在于边界条件->剪枝->逻辑处理->遍历子问题
  - subsets: [78. 子集](https://leetcode.cn/problems/subsets/description/)
  - combinatiosn: [77. 组合 ](https://leetcode.cn/problems/combinations/)
  - premute: [全排列](https://leetcode.cn/problems/permutations/description/)
- stack：单调栈，先进后出，需要通过后续的值，才能判断当前值对应的结果
  - calculate: [224. 基本计算器](https://leetcode.cn/problems/basic-calculator/)
  - valid_bracket：[20. 有效的括号](https://leetcode.cn/problems/valid-parentheses/description/)
  - min_stack：[155. 最小栈](https://leetcode.cn/problems/min-stack/description/)
  - reverse_polish_notation：[150. 逆波兰表达式求值](https://leetcode.cn/problems/evaluate-reverse-polish-notation/)
  - largest_rectangle_area：[84. 柱状图中最大的矩形](https://leetcode.cn/problems/largest-rectangle-in-histogram/description/)
  - largest_rectangle：[85. 最大矩形](https://leetcode.cn/problems/maximal-rectangle/description/)
- tree：树的遍历回溯，常用到递归的方式
  - invert_tree: [226. 翻转二叉树](https://leetcode.cn/problems/invert-binary-tree/description/)
  - check_bst: [98. 验证二叉搜索树](https://leetcode.cn/problems/validate-binary-search-tree/description/)
- dp：常用于多个重叠子问题可推导出主问题的最优解
  - climbing_stairs: [70. 爬楼梯](https://leetcode.cn/problems/climbing-stairs/)
  - min_cost_climbing_stairs: [746. 使用最小花费爬楼梯](https://leetcode.cn/problems/min-cost-climbing-stairs/description/)
  - climbing_stairs_ii：[57. 爬楼梯（第八期模拟笔试）](https://kamacoder.com/problempage.php?pid=1067)
  - bag01: [46. 携带研究材料（第六期模拟笔试）- 01背包问题](https://kamacoder.com/problempage.php?pid=1046)
  - bagfull: [52. 携带研究材料（第七期模拟笔试）- 完全背包](https://kamacoder.com/problempage.php?pid=1052)
- 贪心：遍历局部最优解汇总之后就是全局最优解
  - 
