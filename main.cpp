#include <bits/stdc++.h>
using namespace std;

// function to swap elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// function to print the array
void printArray(int array[], int size) {
  int i;
  cout << " ";
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

// function to rearrange array (find the partition point)
int partition(int array[], int low, int high) {
    
  // select the rightmost element as pivot
  int pivot = array[high];
  
  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
    
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      
      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }
  
  // swap pivot with the greater element at i
  swap(&array[i + 1], &array[high]);
  
  // return the partition point
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
      
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on righ of pivot
    int pi = partition(array, low, high);

    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);

    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
}

// using Divide & Conquer Algorithm
int findMax(int arr[], int index, int l)
{
    int max;
    if(index >= l - 2)
    {
        if(arr[index] > arr[index + 1])
          return arr[index];
        else
          return arr[index + 1];
    }
    max = findMax(arr, index + 1, l);    

    if(arr[index] > max)
      return arr[index];
    else
      return max;
}


int main() {
  int data[] = {11, 32, 34, 54, 58, 90, 120};
  int n = sizeof(data) / sizeof(data[0]);
  int max;
  
  // perform quicksort on data
  quickSort(data, 0, n - 1);
  
  // function to find the maximum no. in a given array.
  max = findMax(data, 0, n);
  
  // display the result of quickSort function
  cout << "\n Sorted Array \n" << endl;
  printArray(data, n);
  cout << endl;
  
  cout << " Maximum Element: " << max << endl;
}