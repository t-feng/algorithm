/*
题目描述
一个DNA序列由A/C/G/T四个字母的排列组合组成。G和C的比例（定义为GC-Ratio）是序列中G和C两个字母的总的出现次数除以总的字母数目（也就是序列长度）。在基因工程中，这个比例非常重要。因为高的GC-Ratio可能是基因的起始点。

给定一个很长的DNA序列，以及要求的最小子序列长度，研究人员经常会需要在其中找出GC-Ratio最高的子序列。


输入描述:
输入一个string型基因序列，和int型子串的长度

输出描述:
找出GC比例最高的子串,如果有多个输出第一个的子串
*/
#include <iostream>
#include <string>

using namespace std;

float calculate(string str)
{
	float count = 0.0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == 'G' || str[i] == 'C') count+=1.0;
	}

	return count / str.size();
}


void GCRatio(string str, int n)
{
	float max = 0.0;
	int index = 0;
	for (int i = 0; i <= str.size() - n; i++)
	{
		string temp = str.substr(i, n);
		float res = calculate(temp);
		if (res > max)
		{
			max = res;
			index = i;
		}
	}

	cout << str.substr(index, n) << endl;
}


int main()
{
	string str;
	int n;
	while (cin >> str >> n)
	{
		GCRatio(str, n);
	}
	return 0;

}




