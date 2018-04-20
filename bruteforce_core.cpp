#include <iostream>
#include <vector>
using namespace std;

void todo(const int& task_count, vector<int> &recursive_value) {
  // TODO: this function gets called automatically for each iteration of brute-force loop.
}


// RecursiveTask
//
// Variables
// task_count: The number of digits
// data_start: List of initial value for each task
// k: The number of current task
// data: List of maximum iteration for each task
// recursive_value: List of current value for each task
// *f: callback function
// 
// Heuristic
// If not the last: recursive with iterate k until it's the last
// If it's the last: now you will get N nested loop, where N is task_count,
//                   so it will call *f function that you have passed it through
void RecursiveTask(const int& task_count, vector<int> &data_start, const int& k, vector<int> &data, vector<int> &recursive_value, void (*f)(const int& task_count, vector<int> &recursive_value)) {
  if (k >= task_count-1) {
    for (int i = data_start[k] ; i < data[k] ; ++i) {
      recursive_value[k] = i;
      (*f)(task_count, recursive_value);
    }
  } else {
    for (int i = data_start[k] ; i < data[k] ; ++i) {
      recursive_value[k] = i;
      RecursiveTask(task_count, data_start, k+1, data, recursive_value, f);
    }
  }  
}