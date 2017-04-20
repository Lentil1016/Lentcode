#pragma once
#include<vector>
#include<string>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Lentcode
{
public:
	Lentcode();
	~Lentcode();

	//problem 1
	std::vector<int> twoSum(std::vector<int>& nums, int target);

	//problem 26
	int removeDuplicates(std::vector<int>& nums);

	//problem 67
	std::string addBinary(std::string a, std::string b);

	//problem 75
	void sortColors(std::vector<int>& nums);

	//problem 84
	int largestRectangleArea(std::vector<int>& heights);

	//problem 88
	void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n);

	//problem 125
	bool isPalindrome(std::string s);

	//problem 344
	std::string reverseString(std::string s);

	//problem 412
	std::vector<std::string> fizzBuzz(int n);

	//problem 400
	int findNthDigit(int n);

	//problem 446
	int numberOfArithmeticSlices(std::vector<int>& A);

	//problem 557
	std::string reverseWord(std::string s);

private:
	int recursion_84(std::vector<int>::iterator &it, std::vector<int>::iterator &it_end, int &max, int past);
};
