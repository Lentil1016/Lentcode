#define L_DEBUG

#include<iostream>
#include<boost/unordered_map.hpp>
#include<vector>
#include<limits.h>
//#include<bitset>
#include"Lentcode.h"
//#include<boost/regex.hpp>
//#include<string>  // for std::string
//#include<numeric> // for std::accumulate
#include<sstream>

using namespace boost;
using namespace std;

Lentcode::Lentcode()
{
}

Lentcode::~Lentcode()
{
}

//Easy problem 1 ACed twoSum
vector<int> Lentcode::twoSum(vector<int>& nums, int target)
{
	unordered_map<long, long>m;//map of [nember a -> index of a's complament
	int i = 0, size = nums.size();
	for (; i < size; i++)
	{
		if (m.find(nums[i]) == m.end())//if a is not recorded
			m[target - nums[i]] = i;//make the complament of a mapping to the index of a
		else
			break;
	}
	vector<int> ret(m[nums[i]] ,i);
	return ret;
}

//Easy problem 26 ACed removeDuplicates
int Lentcode::removeDuplicates(vector<int>& nums)
{
	vector<int>::iterator begin = nums.begin(), end_unique = unique(begin, nums.end());
	return end_unique - begin;
}

//Medium problem 75 ACed 三色One_Pass O(1)排序
void Lentcode::sortColors(vector<int>& nums)
{
	int count_0(0), count_1(count_0), count_2(count_0),i(0);
	vector<int>::iterator itr(nums.begin());
	for(;i<nums.size();i++)
	{
		if (nums[i] == 0)
		{
			swap(*(itr + count_0 + count_1), *(itr + i));
			swap(*(itr + count_0), *(itr + count_0 + count_1));
			count_0++;
		}
		else if (nums[i] == 1)
		{
			swap(*(itr + count_0 + count_1), *(itr + i));
			count_1++;
		}
		else
		{
			count_2++;
		}
	}
}

//Hard problem 84 ACed 最大长方体面积
int Lentcode::largestRectangleArea(vector<int>& heights)
{
	if ((heights.size() == 0))
		return 0;		//判断输入不为空
	vector<int>::iterator it = heights.begin(), it_end = heights.end();
	int max = 0, remain = 0;
	while (it != heights.end())
		remain = recursion_84(it, it_end, max, remain);//跳出递归的两种条件：it迭代至end、当前项小于最底层递归的高度标记，第二种情况需要将上次递归中的count作为rest带入下一次递归
	return max;
}
int Lentcode::recursion_84(vector<int>::iterator &it, vector<int>::iterator &it_end, int &max, int past)
{
	int count = past, height = *it, remain = 0, temp = 0;//进入函数时it为第一项，本层递归的识别标志为height
	while (height != 0)//主循环
	{
		while ((it != it_end) && (height == *it))//将与该层标志相等的项目累加至count
			count++, it++, remain = 0;
		if ((it == it_end) || (height > *it))//迭代至尾部，或下一层低于本层标记时->判断是否为max，并结束本层递归
		{
			if (max < count*height)
				max = count*height;
			return count;
		}
		else//下一项高于本层标记，进入下一层递归
		{
			temp = recursion_84(it, it_end, max, remain); //下层递归结束后返回下层递归的count累加至本层count之上，然后继续主循环
			count += temp - remain;
			remain = temp;
		}
	}
	it++;
	return 0;
}

//Easy problem 88 ACed merge归并排序
void Lentcode::merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
{
	nums1.resize(m+n);
	std::merge(nums1.rbegin()+n, nums1.rend(),\
			nums2.rbegin(), nums2.rend(),\
			nums1.rbegin(),greater<int>());
}

//Easy problem 344 ACed reverseString
string reverseString(string s) {
	std::reverse(s.begin(), s.end());
	return s;
}

//Easy problem 412 ACed fizzBuzz
vector<string> Lentcode::fizzBuzz(int n) {
	vector<string> rtn;
	stringstream ss;
	for (int i = 1; i <= n; i++)
	{
		if ((i % 5 == 0) || (i % 3 == 0))
		{
			if (i % 3 == 0)
				ss << "Fizz";
			if (i % 5 == 0)
				ss << "Buzz";
			rtn.push_back(ss.str());
			ss.str("");
		}
		else
		{
			ss << i;
			rtn.push_back(ss.str());
			ss.str("");
		}
	}
	return rtn;

}

//Hard problem 446 ACed numberOfArithmeticSlices
int Lentcode::numberOfArithmeticSlices(vector<int>& A)
{
	if(A.size() < 3)
		return 0;

	vector<unordered_map<int,int> > dp(A.size());
	unordered_map<int,int>::iterator iter;
	int step,i, j, ret = 0;

	for(i=0; i<A.size(); i++)
	{
		for(j=0; j<i; j++)
		{
			step = A[i]-A[j];
			if ((long)step + (long)A[j] != A[i])
				continue;
			dp[i][step] += 1;
			if((iter=dp[j].find(step)) != dp[j].end())
			{
				dp[i].find(step)->second += iter->second;
				//如果有前者A[j]在step上有记录，说明已经达到至少三连，
				//那A[j]的全部路径组合加1就是A[i]的全部路径组合
				ret += dp[j].find(step)->second;
			}
		}
	}

	return ret;
}

// problem 67
string Lentcode::addBinary(string a, string b)
{
	//a.reserve();
	//b.reserve();
	int size = max(a.size(), b.size());
	a.resize(size, '0');
	b.resize(size, '0');
	cout << b << endl;
	cout << a << endl;
	return a;
}



