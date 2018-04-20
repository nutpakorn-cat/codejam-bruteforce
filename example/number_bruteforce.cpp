#include <iostream>
#include <vector>
using namespace std;

// User callback function
// For example 
// We want to brute-force 3 digits, so this will print 3 digits brute-force number
// with [0,5] value
void todo(const int& task_count, vector<int> &recursive_value) {
  for (int i = 0 ; i < task_count ; ++i) {
    cout << recursive_value[i] << " ";
  }
  cout << endl;
}

// Include from bruteforce_core.cpp
// It's unnecessery to customize, Just a system core.
void RecursiveTask(const int& task_count, vector<int> &data_start, const int& k, vector<int> &data, vector<int> &recursive_value, void (*f)(const int& task_count, vector<int> &recursive_value)) {
  if (k >= task_count-1) {
    for (int i = data_start[k] ; i <= data[k] ; ++i) {
      recursive_value[k] = i;
      (*f)(task_count, recursive_value);
    }
  } else {
    for (int i = data_start[k] ; i <= data[k] ; ++i) {
      recursive_value[k] = i;
      RecursiveTask(task_count, data_start, k+1, data, recursive_value, f);
    }
  }  
}

int main() {
  // For example, expect 3 digits
  const int digits = 3;
  
  // Initial list
  vector<int> data;
  vector<int> data_start;
  vector<int> recursive_data(digits, 0);

  // Define a maximum value for each task
  data.push_back(5);
  data.push_back(5);
  data.push_back(5);

  // Define a intial value for each task
  data_start.push_back(0);
  data_start.push_back(0);
  data_start.push_back(0);

  RecursiveTask(digits, data_start, 0, data, recursive_data, todo);
  return 0;
}