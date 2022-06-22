/**
 * Problem: Given an array of integers nums and an integer target,
 * return indices of the two numbers such that they add up to target.
 *
 * @file two_sum.cc
 * @author Rohit Gautam
 */
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * Search for the complement of num[i] in hash_map,
 * if not found then store the num in the hash_map
 *
 * Time-Complexity: O(N)
 * Space-Complexity: O(N) for hash_map
 *
 * @param nums input arr to search for two sum
 * @param target two num from arr add upto target
 * @return pair of indices which add up to target
 */
pair<int, int> two_sum(vector<int>& nums, int target) {
  unordered_map<int, int> comp_map;
  for (int i = 0; i < nums.size(); i++) {
    int complement = target - nums[i];
    if (comp_map.find(complement) != comp_map.end()) {
      return {comp_map.find(complement)->second, i};
    }
    comp_map[nums[i]] = i;
  }
  return {-1, -1};
}

int main() {
  vector<int> nums{3, 6, 4, 5, 2};
  int target = 6;

  auto result = two_sum(nums, target);
  cout << "[ " << result.first << ", " << result.second << " ]\n";

  return 0;
}