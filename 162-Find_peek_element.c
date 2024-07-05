#include <stdio.h>
// int findPeakElement(int *nums, int numsSize) {
//   for (int i = 0; i < numsSize; i++) {
//     if ((i == 0 || nums[i - 1] < nums[i]) &&
//         (i == numsSize - 1 || nums[i] > nums[i + 1]))
//       return i;
//   }
// }

int findPeakElement(int *nums, int numsSize) {
  if (numsSize == 1)
    return 0;
  if (nums[0] > nums[1])
    return 0;
  if (nums[numsSize - 1] > nums[numsSize - 2])
    return numsSize - 1;
  int low = 1;
  int high = numsSize - 2;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
      return mid;
    else if (nums[mid] > nums[mid - 1])
      low = mid + 1;
    else
      low = high = mid - 1;
  }
  return -1;
}

int main() {
  int arr1[] = {1, 2, 3, 1};
  int arr1Size = sizeof(arr1) / sizeof(arr1[0]);
  printf("%d", findPeakElement(arr1, arr1Size));

  int arr2[] = {1, 2, 1, 3, 5, 6, 4};
  int arr2Size = sizeof(arr2) / sizeof(arr2[0]);
  printf("%d", findPeakElement(arr2, arr2Size));

  int arr3[] = {1, 2};
  int arr3Size = sizeof(arr3) / sizeof(arr3[0]);
  printf("%d", findPeakElement(arr3, arr3Size));

  int arr4[] = {1};
  int arr4Size = sizeof(arr4) / sizeof(arr4[0]);
  printf("%d", findPeakElement(arr4, arr4Size));
  return 0;
}
