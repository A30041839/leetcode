class Solution {
public:
  int findDuplicate(vector<int>& nums) {
    return findDuplicate1(nums);
  }

  int findDuplicate1(vector<int>& nums) {
    int n = nums.size();
    int low = 1, high = n - 1;
    while (low < high) {
      int mid = low + (high - low) / 2;
      int cnt = 0;
      for (int i = 0; i < n; ++i) {
        if (nums[i] <= mid) {
          cnt++;
        }
      }
      if (cnt > mid) {
        high = mid;
      }else {
        low = mid + 1;
      }
    }
    return low;
  }
};