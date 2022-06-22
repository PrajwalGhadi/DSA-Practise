/**
 * Problem: Given an array of integers nums and an integer target,
 * return the two numbers such that they add up to target.
 *
 * @file pair_sum.cc
 * @author Rohit Gautam
 */
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * Search for the complement of num[i] in hash_set,
 * if not found then store the num in the hash_set
 *
 * Time-Complexity: O(N)
 * Space-Complexity: O(N) for hash_set
 *
 * @param nums input arr to search for two sum
 * @param target two num from arr add upto target
 * @return two numbers which add up to target
 */
vector<int> pair_sum(vector<int>& nums, int target) {
  unordered_set<int> comp_set;
  for (int i = 0; i < nums.size(); i++) {
    int complement = target - nums[i];

    if (comp_set.find(complement) != comp_set.end()) {
      return {complement, nums[i]};
    }
    comp_set.insert(nums[i]);
  }
  return {};
}

int main() {
  vector<int> nums{8, 3, 2, 5, -4, 7, 12};
  int target = 4;
  auto result = pair_sum(nums, target);
  if (result.size() > 0) {
    cout << "[ " << result[0] << ", " << result[1] << " ]\n";
  } else {
    cout << "No pair found!\n";
  }
  return 0;
}