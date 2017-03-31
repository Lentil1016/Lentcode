#include"Lentcode.h"
#include <iostream>
#include <string>  // for std::string
#include <vector>  // for std::vector
#include <numeric> // for std::accumulate

using namespace std;

int main(int argc, char **argv)
{

	Lentcode obj;

	//problem 1
	/*
	vector<int> nums = {1,2,3,5,8,10};
	int target = 10;
	vector<int> ans=obj.twoSum(nums,target);
	cout << ans[0] << "/n" << ans[1] << endl;
	cin.get();
	return 0;
	*/

	//problem 26
	/*
	vector<int> nums = { 1,2,3,4,4,5 };
	int ans = obj.removeDuplicates(nums);
	cout << ans << endl;
	cin.get();
	*/

	//problem 88
	/*
	int n1[] = { 1,2,2,3,4 }, n2[] = { 2,3,4,4,5 };
	vector<int> num1(n1,n1+5),num2(n2,n2+5);
	int m = num1.size(), n = num2.size();
	obj.merge(num1, m, num2, n);
	cout<<num1.size()<<endl;
	for (int i = 0; i < m + n; i++)
		cout <<"num1["<<i<<"]"<< num1[i] << ",";
	cout << endl;
	*/

	//problem 67
	/*
	string a = { "10111111" };
	string b = { "010000" };
	obj.addBinary(a, b);
	cin.get();
	*/

	//problem 84
	/*
	vector<int> height = { 2,1,4,5,1,3,3};
	int max=obj.largestRectangleArea(height);
	cout << max << endl;
	cin.get();
	*/


	//problem 446
	int a[] = {0,2000000000,-294967296};
	vector<int> input(a,a+3);
	cout<< obj.numberOfArithmeticSlices(input)<<endl;
	return 0;

}
