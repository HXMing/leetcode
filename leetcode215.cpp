#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int findKthLargest(vector<int> &nums, int k) {
  priority_queue<int> q;
  for (int i = 0; i < nums.size(); ++i) {
    q.push(-nums[i]);
    if (q.size() > k) {
      q.pop();
    }
  }
  // int ans;
  // while(!q.empty()){
  //     ans=q.top();
  //     q.pop();
  // }
  return -q.top();
}

int main() {
  // vector<int> nums = {3,2,1,5,6,4};
  // int k = 2;
  vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
  int k = 4;
  cout << findKthLargest(nums, k) << "\n";
  return 0;
}
