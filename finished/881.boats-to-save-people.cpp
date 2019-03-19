/*
 * @lc app=leetcode id=881 lang=cpp
 *
 * [881] Boats to Save People
 *
 * https://leetcode.com/problems/boats-to-save-people/description/
 *
 * algorithms
 * Medium (41.27%)
 * Total Accepted:    11.8K
 * Total Submissions: 27.5K
 * Testcase Example:  '[1,2]\n3'
 *
 * The i-th person has weight people[i], and each boat can carry a maximum
 * weight of limit.
 * 
 * Each boat carries at most 2 people at the same time, provided the sum of the
 * weight of those people is at most limit.
 * 
 * Return the minimum number of boats to carry every given person.  (It is
 * guaranteed each person can be carried by a boat.)
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: people = [1,2], limit = 3
 * Output: 1
 * Explanation: 1 boat (1, 2)
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: people = [3,2,2,1], limit = 3
 * Output: 3
 * Explanation: 3 boats (1, 2), (2) and (3)
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: people = [3,5,3,4], limit = 5
 * Output: 4
 * Explanation: 4 boats (3), (3), (4), (5)
 * 
 * Note:
 * 
 * 
 * 1 <= people.length <= 50000
 * 1 <= people[i] <= limit <= 30000
 * 
 * 
 * 
 * 
 * 
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
  public:
  int numRescueBoats(vector<int>& people, int limit) {
    // sort
    sort(people.begin(), people.end(), greater<int>());

    // ?????????????????????????????
    // ????????????????
    int i = 0;                  // heaviest
    int j = people.size() - 1;  // lightest
    int res = 0;

    while (i <= j) {
      res++;

      if (people[i] + people[j] <= limit) {
        // ?????????????
        j--;
      }
      // ?????????????????????
      i++;
    }

    return res;
  }
};

/*
int main(void) {
  Solution test;
  vector<int> people = {3, 2, 2, 1};
  int limit = 3;
  cout << (test.numRescueBoats(people, limit)) << endl;
}
*/
