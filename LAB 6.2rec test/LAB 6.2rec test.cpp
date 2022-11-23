#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab6.2 rec/Lab6.2 rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LAB62rectest
{
	TEST_CLASS(LAB62rectest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double t = 0;
			int arr[8] = { 0, -2, 3, 5, 1, -1, -6, 8 };
			int amount = 0;
			double serednie_arif = 0;
			int all_i_elements = 0;
			t = calculate(arr, 8, 0, serednie_arif, all_i_elements, amount);
			Assert::AreEqual(t, 3.5);
		}
	};
}
