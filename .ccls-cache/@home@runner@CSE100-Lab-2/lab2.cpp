#include <iostream>
using namespace std;

void print(int *array, int size) {
  for (int i = 0; i <= size; i++)
    cout << array[i] << ";";
  cout << endl;
}

void merge(int array[], int left, int middle, int right) {
  // dividing the given array into two halves
  int firsthalf = middle - left + 1;
  int secondhalf = right - middle;
  // creating two temporary arrays
  int temp1[firsthalf], temp2[secondhalf];
  // copying the data from the two halves into two temporary arrays
  for (int m = 0; m < firsthalf; m++)
    temp1[m] = array[left + m];
  for (int n = 0; n < secondhalf; n++)
    temp2[n] = array[middle + 1 + n];
  // merging the temporary arrays into a single array
  int a = 0;
  int b = 0;
  int c = left;
  while (a < firsthalf && b < secondhalf) {
    if (temp1[a] <= temp2[b]) {
      array[c] = temp1[a];
      a++;
    } else {
      array[c] = temp2[b];
      b++;
    }
    c++;
  }
  while (a < firsthalf) {
    array[c] = temp1[a];
    a++;
    c++;
  }
  while (b < secondhalf) {
    array[c] = temp2[b];
    b++;
    c++;
  }
}
// sorting each of the divided arrays using mergeSort() function
void mergeSort(int array[], int left, int right) {
  if (left >= right) {
    return;
  }
  int middle = left + (right - left) / 2;
  mergeSort(array, left, middle);
  mergeSort(array, middle + 1, right);
  merge(array, left, middle, right);
}
// function to print the resulting array
void printArray(int Array[], int size) {
  for (int d = 0; d < size; d++)
    cout << Array[d] << " ";
}


int main() {
  int array[] = {5, 3, 2, 1, 6, 4};
  int array_size = sizeof(array) / sizeof(array[0]);
  //cin >> n;   // take in amount
  //int arr[n]; // create an array with space for that many elements
  // for (int i = 0; i < n; i++) {
  //   cin >> arr[i]; // take each into the array 1 at a time
  // }
  mergeSort(array, 0, array_size-1);
}