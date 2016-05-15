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
		return 0;		//�ж����벻Ϊ��
	vector<int>::iterator it = heights.begin(), it_end=heights.end();
	int max = 0, remain=0;
	while (it != heights.end())
		remain = recursion_84(it, it_end, max, remain);//�����ݹ������������it������end����ǰ��С����ײ�ݹ�ĸ߶ȱ�ǣ��ڶ��������Ҫ���ϴεݹ��е�count��Ϊrest������һ�εݹ�
	return max;
}

int Lentcode::recursion_84(vector<int>::iterator &it, vector<int>::iterator &it_end, int &max, int past)
{
	int count = past, height = *it, remain=0, temp=0;//���뺯��ʱitΪ��һ�����ݹ��ʶ���־Ϊheight
	while (height!=0)//��ѭ��
	{
		while ((it != it_end) && (height == *it))//����ò��־��ȵ���Ŀ�ۼ���count
			count++, it++,remain=0;
		if ((it == it_end)||(height > *it))//������β��������һ����ڱ�����ʱ->�ж��Ƿ�Ϊmax������������ݹ�
		{
			if (max < count*height)
				max = count*height;
			return count;
		}
		else//��һ����ڱ����ǣ�������һ��ݹ�
		{
			temp = recursion_84(it, it_end, max, remain); //�²�ݹ�����󷵻��²�ݹ��count�ۼ�������count֮�ϣ�Ȼ�������ѭ��
			count +=temp-remain;
			remain = temp;
		}
	}
	it++;
	return 0;
}