#include "pch.h"
#include "CppUnitTest.h"
#include "../NAM/NAM.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(TestNAM)
	{
	public:
		
		TEST_METHOD(TestOperatorEqual)
		{
			String str = "hello";
			String str2;
			str2 = str;
			Assert::IsTrue(str2 == "hello");
		}

		TEST_METHOD(TestOperatorAdd)
		{
			String str = "hel";
			String str2 = "lo";
			String str3;
			str3 = str + str2;
			Assert::IsTrue(str3 == "hello");
		}

		TEST_METHOD(TestOperatorСomparison)
		{
			String str = "hello";
			String str2 = "hello";
			Assert::IsTrue(str == str2);
		}

		TEST_METHOD(TestSizeOfArray)
		{
			String str = "hello";
			Assert::IsTrue(str.SizeOfArray() == 5);
		}

		TEST_METHOD(TestReplace)
		{
			String str = "hello";
			str.Replace("lo", "p");
			Assert::IsTrue(str == "help");
		}

		TEST_METHOD(TestMarkAlg)
		{
			String str = "1000";
			Markov<String> mark1(1);
			Assert::IsTrue(str.MarkAlg(mark1) == "||||||||");

			str = "||*|||";
			Markov<String> mark2(2);
			Assert::IsTrue(str.MarkAlg(mark2) == ".||||||");
		}
	};
}
