/**
 * UNDONE!!!
 * Problem: Given two sorted arrays nums1 and nums2 of size m and n respectively,
 * return the median of the two sorted arrays.
 * The overall run time complexity should be O(log (m+n)).
 *
 * @file median_of_two_sorted_array.cc
 * @author Rohit Gautam
 */
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Find the median of two adjacent sorted array.
 *
 * @param mid mid-point of the combined array.
 * @param nums1 input sorted array 1.
 * @param nums2 input sorted array 2.
 * @return median of combined adjacent arrays.
 */
double find_median(int mid, vector<int>& nums1, vector<int>& nums2) {
  if ((nums1.size() + nums2.size()) % 2 == 0) {
    int i1 = mid - 1;
    int i2 = mid;
    int a1 = (i1 < nums1.size()) ? nums1[i1] : nums2[i1 - nums1.size()];
    int a2 = (i2 < nums1.size()) ? nums1[i2] : nums2[i2 - nums1.size()];
    return static_cast<float>((a1 + a2)) / 2;
  }
  return (mid < nums1.size()) ? nums1[mid] : nums2[mid - nums1.size()];
}

/**
 * Find the median of two sorted array.
 *
 * @param nums1 input sorted array 1.
 * @param nums2 input sorted array 2.
 * @return median of combined two arrays.
 */
double find_median_sorted_array(vector<int>& nums1, vector<int>& nums2) {
  int len = nums1.size() + nums2.size();
  int mid = floor(len / 2);

  if (nums1[0] < nums2[0] && nums1[nums1.size() - 1] < nums2[0]) {
    // arr1 < arr2
    return find_median(mid, nums1, nums2);
  } else if (nums2[0] < nums1[0] && nums2[nums2.size() - 1] < nums1[0]) {
    // arr1 > arr2
    return find_median(mid, nums2, nums1);
  } else {
    // arr1 & arr2 are mixed up
    // WIP
  }
  return 0;
}

int main() {
  vector<int> nums1{1, 2, 3};
  vector<int> nums2{4, 5};
  cout << find_median_sorted_array(nums1, nums2) << '\n';
  return 0;
}