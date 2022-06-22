/**
 * Problem: Given a sorted array of integers nums and an integer target,
 * return the two numbers such that they add up to target.
 *
 * @file pair_sum_sorted.cc
 * @author Rohit Gautam
 */
#include <iostream>
#include <vector>

using namespace std;

/**
 * Since the array is sorted, two numbers are compared from both the end.
 * If sum of two numbers is less than the target then move left pointer to right,
 * else if sum is greater than target then move right pointer towards left.
 *
 * Time-Complexity: O(N) worst-case, O(1) best-case
 * Space-Complexity: O(1)
 *
 * @param nums input arr to search for two sum
 * @param target two num from arr add upto target
 * @return two numbers which add up to target
 */
vector<int> pair_sum_sorted(vector<int>& nums, int target) {
  int i = 0;
  int j = nums.size() - 1;

  while (i < j) {
    if (nums[i] + nums[j] < target) {
      i++;
    } else if (nums[i] + nums[j] > target) {
      j--;
    } else {
      return {nums[i], nums[j]};
    }
  }
  return {};
}

int main() {
  vector<int> nums{-3, 1, 3, 4, 5, 7, 12};
  int target = 5;
  auto result = pair_sum_sorted(nums, target);
  if (result.size() > 0) {
    cout << "[ " << result[0] << ", " << result[1] << " ]\n";
  } else {
    cout << "No pair found!\n";
  }
  return 0;
}