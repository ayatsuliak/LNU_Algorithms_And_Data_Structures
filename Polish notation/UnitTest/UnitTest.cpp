#include "pch.h"
#include "CppUnitTest.h"
#include "..\Polish notation\PolishNotation.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(TestPolishNotation)
	{
	public:
		
		TEST_METHOD(TestToPostfix)
		{
			string str = "(1+2)*4+3";
			string str2 = ToPostfix(str);
			Assert::IsTrue(str2 == "12+4*3+");
		}

		TEST_METHOD(TestPriority)
		{
			char ch = '(';
			Assert::IsTrue(Priority(ch) == 0);
			char ch1 = '^';
			Assert::IsFalse(Priority(ch) == 2);
		}

		TEST_METHOD(TestIsOperator)
		{
			char ch = '*';
			Assert::IsTrue(IsOperator(ch) == 2);
			char ch1 = '^';
			Assert::IsTrue(Priority(ch) == 2);
			char ch2 = '-';
			Assert::IsFalse(Priority(ch) == 1);
		}

		TEST_METHOD(TestReversePolishNotation)
		{
			string str = "3*(4+5)-(6-2)*4";
			string str2 = ToPostfix(str);
			Assert::IsTrue(ReversePolishNotation(str2) == 11);
		}
	};
}
