// 217. Contains Duplicate
// Easy
// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

  class Solution {
  public:
      bool containsDuplicate(vector<int>& nums) {
          map<int,int> mp; // Important
          for(auto i : nums) mp[i]++; // see here
          bool flag = false;
          for(auto i : mp){
              if(i.second >= 2) return true;
          }
          return flag;
      }
  };
