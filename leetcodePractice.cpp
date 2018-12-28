include<iostream>
#include<vector>
#include<string>
using namespace std;
using std::string;

class Solution {
public:
	vector<int> int2binary(int n) {
		vector<int> res;
		while(n) {
			res.push_back();
			n >> 1;
		}
		return res;
	}
};

int main()
{
	Solution leet;
	int b[] = {1,2,3,4,3};
	vector<int> nums(b,b+5);
	
	//cout<<leet.addDigits(num)<<endl;
	cout<<leet.findPeak(nums)<<endl;
	return 0;
}
