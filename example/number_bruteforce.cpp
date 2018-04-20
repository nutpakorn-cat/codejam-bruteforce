#include <iostream>
#include <vector>
using namespace std;

void todo(const int& task_count, vector<int> &recursive_value) {
  for (int i = 0 ; i < task_count ; ++i) {
    cout << recursive_value[i] << " ";
  }
  cout << endl;
}

void RecursiveTask(const int& task_count, vector<int> &data_start,
                  const int& k, vector<int> &data, vector<int> &recursive_value, void (*f)(const int& task_count, vector<int> &recursive_value)) {
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

int main() {
    vector<int> data;
    vector<int> data_start;
    vector<int> recursive_data;
    data.push_back(5);
    data.push_back(3);
    data.push_back(2);

    data_start.push_back(0);
    data_start.push_back(0);
    data_start.push_back(0);

    recursive_data.push_back(0);
    recursive_data.push_back(0);
    recursive_data.push_back(0);

    RecursiveTask(3, data_start, 0, data, recursive_data, todo);

    return 0;
}