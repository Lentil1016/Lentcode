#include"Lentcode.h"
#include "vector"
#include "iostream"

int main()
{
	Lentcode obj;
	vector<int> nums = {1,2,3,5,8,10};
	int target = 10;
	vector<int> ans=obj.twoSum(nums,target);
	cout << ans[0] << "/n" << ans[1] << endl;
	cin.get();
	return 0;
}