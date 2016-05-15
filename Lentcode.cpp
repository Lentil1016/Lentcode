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
}

int Lentcode::removeDuplicates(vector<int>& nums)
{
	vector<int>::iterator begin = nums.begin(), end_unique = unique(begin, nums.end());
	return end_unique-begin;
}

int Lentcode::largestRectangleArea(vector<int>& heights)
{
	if ((heights.size() == 0))
		return 0;		//判断输入不为空
	vector<int>::iterator it = heights.begin(), it_end=heights.end();
	int max = 0, remain=0;
	while (it != heights.end())
		remain = recursion_84(it, it_end, max, remain);//跳出递归的两种条件：it迭代至end、当前项小于最底层递归的高度标记，第二种情况需要将上次递归中的count作为rest带入下一次递归
	return max;
}

int Lentcode::recursion_84(vector<int>::iterator &it, vector<int>::iterator &it_end, int &max, int past)
{
	int count = past, height = *it, remain=0, temp=0;//进入函数时it为第一项，本层递归的识别标志为height
	while (height!=0)//主循环
	{
		while ((it != it_end) && (height == *it))//将与该层标志相等的项目累加至count
			count++, it++,remain=0;
		if ((it == it_end)||(height > *it))//迭代至尾部，或下一层低于本层标记时->判断是否为max，并结束本层递归
		{
			if (max < count*height)
				max = count*height;
			return count;
		}
		else//下一项高于本层标记，进入下一层递归
		{
			temp = recursion_84(it, it_end, max, remain); //下层递归结束后返回下层递归的count累加至本层count之上，然后继续主循环
			count +=temp-remain;
			remain = temp;
		}
	}
	it++;
	return 0;
}