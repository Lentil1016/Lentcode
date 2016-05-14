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
	int i;
	for (i=0; i < nums.size(); i++)
	{
		if (m.find(nums[i]) == m.end())//if a is not recorded
			m[target - nums[i]] = i;//make the complament of a mapping to the index of a
		else
			break;
	}
	vector<int> ret = { m[nums[i]] ,i};
	return ret;
}//arithmetic 1