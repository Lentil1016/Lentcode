#include "Lentcode.h"
#include"iostream"
#include <unordered_map>  

using namespace std;

Lentcode::Lentcode()
{
}


Lentcode::~Lentcode()
{
}


vector<int> Lentcode::twoSum(vector<int>& nums, int target)
{
	unordered_map<long, long>m;//map of [nember a -> index of a's complament
	int i=0, size = nums.size();
	for (; i < size; i++)
	{
		if (m.find(nums[i]) == m.end())//if a is not recorded
			m[target - nums[i]] = i;//make the complament of a mapping to the index of a
		else
			break;
	}
	vector<int> ret = { m[nums[i]] ,i};
	return ret;
}//arithmetic 1


int Lentcode::removeDuplicates(vector<int>& nums)
{
	
	vector<int>::iterator begin = nums.begin(), end_unique = unique(begin, nums.end());
	return end_unique-begin;
}//arithmetic 26