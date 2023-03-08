#include <iostream>

const int MOD = 1000000007;

int merge_and_count_inversions(int* sequence, int* temp, int left, int mid, int right) {
  int inversions = 0;

  int left_pointer = left;
  int right_pointer = mid;
  int temp_pointer = left;

  // Merge the two halves and count the number of inversions
  while (left_pointer < mid && right_pointer < right) {
    if (sequence[left_pointer] <= sequence[right_pointer]) {
      temp[temp_pointer++] = sequence[left_pointer++];
    } else {
      inversions = (inversions + mid - left_pointer) % MOD;
      temp[temp_pointer++] = sequence[right_pointer++];
    }
  }

  // Copy the remaining elements from the left half and the right half to the temp array
  while (left_pointer < mid) {
    temp[temp_pointer++] = sequence[left_pointer++];
  }
  while (right_pointer < right) {
    temp[temp_pointer++] = sequence[right_pointer++];
  }

  // Copy the sorted elements from the temp array back to the original array
  for (int i = left; i < right; i++) {
    sequence[i] = temp[i];
  }

  return inversions;
}

int count_inversions(int* sequence, int* temp, int left, int right) {
  if (right - left <= 1) {
    return 0;
  }

  int mid = (left + right) / 2;
  int left_inversions = count_inversions(sequence, temp, left, mid);
  int right_inversions = count_inversions(sequence, temp, mid, right);
  int split_inversions = merge_and_count_inversions(sequence, temp, left, mid, right);

  return (left_inversions + right_inversions + split_inversions) % MOD;
}

int main() {
  int n;
  std::cin >> n;

  int* sequence = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> sequence[i];
  }

  int* temp = new int[n];
  std::cout << count_inversions(sequence, temp, 0, n) << std::endl;

  delete[] sequence;
  delete[] temp;

  return 0;
}

// #include <iostream>
// #include <algorithm>

// // MOD is the number to take the modulus with
// const int MOD = 1000000007;

// int count_inversions(int* sequence, int n) {
//   // If the length of the sequence is 0 or 1, return 0
//   if (n <= 1) {
//     return 0;
//   }

//   // Recursively count the number of inversions in the left half and the right half
//   int left_inversions = count_inversions(sequence, n / 2);
//   int right_inversions = count_inversions(sequence + n / 2, n - n / 2);
//   int split_inversions = 0;

//   // Sort the left half and the right half in ascending order
//   std::sort(sequence, sequence + n / 2);
//   std::sort(sequence + n / 2, sequence + n);

//   // Initialize two pointers to the first element in the left half and the right half, respectively
//   int left_pointer = 0;
//   int right_pointer = n / 2;
//   while (left_pointer < n / 2 && right_pointer < n) {
//     // If the element at left_pointer is greater than the element at right_pointer,
//     // increment split_inversions by the number of elements remaining in the left half
//     // and increment right_pointer
//     if (sequence[left_pointer] > sequence[right_pointer]) {
//       split_inversions += n / 2 - left_pointer;
//       right_pointer++;
//     } else {
//       // Otherwise, increment left_pointer
//       left_pointer++;
//     }
//   }

//   // Return the sum of the number of inversions in the left half, the right half, and across the two halves
//   return (left_inversions + right_inversions + split_inversions) % MOD;
// }

// int main() {
//   int n;
//   std::cin >> n;

//   // Read in the sequence of integers
//   int* sequence = new int[n];
//   for (int i = 0; i < n; i++) {
//     std::cin >> sequence[i];
//   }

//   // Print the number of inversions
//   std::cout << count_inversions(sequence, n) << std::endl;

//   // Deallocate the dynamically-allocated array
//   delete[] sequence;

//   return 0;
// }
