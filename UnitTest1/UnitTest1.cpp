#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_7.3.2/Lab_7.3.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int** a = new int* [4];
			for (int i = 0; i < 4; i++)
				a[i] = new int[4];

			int b[][6]
			{	{65, 8, 9, 15},
				{15, -54, 9, 99},
				{4, 8, 9, 3},
				{9, 15, 100, 100},
			};


			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					a[i][j] = b[i][j];
				}
			}
			int min = a[0][0];
			Find(a, 4, 4, min);
			Assert::AreEqual(min, 23);
			for (int i = 0; i < 4; i++)
				delete[] a[i];
			delete[] a;
		}
	};
}
