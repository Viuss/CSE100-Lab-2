#include <iostream>
using namespace std;

void print(int *array, int size) {
  for (int i = 0; i <= size; i++)
    cout << array[i] << ";";
  cout << endl;
}

void insertionSort(int *array, int size) {
  int key, j;
  for (int i = 1; i < size; i++) {
    key = array[i]; // take value
    j = i;

    while (j > 0 && array[j - 1] > key) {
      array[j] = array[j - 1];
      j--;
    }
    array[j] = key;  // insert in right place
    print(array, i); // print current assortment
  }
}

int main() {
  int n;
  cin >> n;   // take in amount
  int arr[n]; // create an array with space for that many elements
  for (int i = 0; i < n; i++) {
    cin >> arr[i]; // take each into the array 1 at a time
  }
  insertionSort(arr, n);
}