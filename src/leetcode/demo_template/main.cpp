#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <string>
#include <tuple>
#include <vector>
#include <unordered_set>

#include "spdlog/fmt/ranges.h"
#include "spdlog/spdlog.h"

using namespace std;

class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<unordered_set<int>> dq(numCourses);
    for (int i = 0; i < prerequisites.size(); i++) {
      for (int j = 1; j < prerequisites[i].size(); j++) {
        if (dq[prerequisites[i][j]].find(prerequisites[i][0]) != dq[prerequisites[i][j]].end()) {
          return false;
        }
        dq[prerequisites[i][0]].insert(prerequisites[i][j]);
        dq[prerequisites[i][0]].insert(dq[prerequisites[i][j]].begin(), dq[prerequisites[i][j]].end());
      }
    }
    for (int i = 0; i < numCourses; i++) {
      if (dq[i].find(i) != dq[i].end()) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution s;
  vector<vector<int>> prerequisites{{1,0}, {0,1}};
  cout << s.canFinish(2, prerequisites) << endl;
  // for (auto it = a2; it != a4; it++) {
  //   spdlog::info("{}->", *it);
  // }
  return 0;
}