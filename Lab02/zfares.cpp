#include <iostream>
using namespace std;

void print(int *array, int size) {
  for (int i = 0; i <= size; i++)
    cout << array[i] << ";";
  //cout << endl;
}

void merge(int array[], int left, int middle, int right) {
  // split array into two halves
  //print(array,6);
  // cout << left << endl;
  // cout << middle << endl;
  // cout << right << endl;
  int firsthalf = middle - left + 1;
  // cout << "1st half" << endl;
  // cout << firsthalf << endl;
  int secondhalf = right - middle;
  // cout << "2nd half" << endl;
  // cout << secondhalf << endl;
  // create two temp arrays
  int temp1[firsthalf], temp2[secondhalf];
  // copying the data from the two halves into two temporary arrays
  for (int m = 0; m < firsthalf; m++)
    temp1[m] = array[left + m];
  for (int n = 0; n < secondhalf; n++)
    temp2[n] = array[middle + 1 + n];
  // merging the temporary arrays into a single array
  int inc1 = 0;
  int inc2 = 0;
  int base = left;
  while (inc1 < firsthalf && inc2 < secondhalf) {
    if (temp1[inc1] <= temp2[inc2]) {
      array[base] = temp1[inc1];
      inc1++;
    } else {
      array[base] = temp2[inc2];
      inc2++;
    }
    base++;
  }
  while (inc1 < firsthalf) {
    array[base] = temp1[inc1];
    inc1++;
    base++;
  }
  while (inc2 < secondhalf) {
    array[base] = temp2[inc2];
    inc2++;
    base++;
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


int main() {
  int length;
  cin >> length;
  int array[length];
    for(int i=0;i<length;i++)
    {
        cin>>array[i];
    }
  int array_size = sizeof(array) / sizeof(array[0]);
  //cin >> n;   // take in amount
  //int arr[n]; // create an array with space for that many elements
  // for (int i = 0; i < n; i++) {
  //   cin >> arr[i]; // take each into the array 1 at a time
  // }
  mergeSort(array, 0, array_size-1);
  print(array,array_size-1);
  return 0;
}