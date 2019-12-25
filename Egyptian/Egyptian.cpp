﻿/*
题目描述
分子为1的分数称为埃及分数。现输入一个真分数(分子比分母小的分数，叫做真分数)，请将该分数分解为埃及分数。如：8/11 = 1/2+1/5+1/55+1/110。
输入描述:
输入一个真分数，String型

输出描述:
输出分解后的string
*/
#include<iostream>
using namespace std;
int main() {
	char ch;
	int a, b;
	while (cin >> a >> ch >> b)
	{
		while (a != 1) /*最终要达到的目标是分解式中所有分数的分子都为1，若不是则需要进行处理，故分子是否为1作为循环条件。
					                          不要改为b%a,否则虽然原理对但是分解式不是测试用例给出的那个分解结果*/
		{
			if (b % (a - 1) == 0)/*当一个真分数分子不为1时，首先不是进行贪心算法，而是先判断能否进行一个偷巧的分解，即
								                                    若b%(a-1)==0,则a/b=1/[b/(a-1)]+1/b*/
			{
				cout << 1 << '/' << b / (a - 1) << '+';
				a = 1;
			}
			else
			{
				int c = b / a + 1;
				cout << 1 << "/" << c << "+";
				a = a - b%a;
				b = b*c;
				if (b%a == 0)
				{
					b = b / a;
					a = 1;
				}
			}
		}
		cout << a << "/" << b << endl;//分解式中的最后一个分数分子为1时，输出最后一个埃及分数
	}
	return 0;
}

