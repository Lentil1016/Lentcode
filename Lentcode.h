#pragma once
#include<vector>
#include <algorithm>
#include <cstdlib>
#include<map>
using namespace std;

class Lentcode
{
public:
	Lentcode();
	~Lentcode();    

	//summary: problem 1
	vector<int> twoSum(vector<int>& nums, int target);

	//summary: problem 26
	int removeDuplicates(vector<int>& nums);

	//summary: problem 84 (statu:WA)
	int largestRectangleArea(vector<int>& heights);

private:
	int recursion_84(vector<int>::iterator &it, vector<int>::iterator &it_end, int &max, int past);
};

