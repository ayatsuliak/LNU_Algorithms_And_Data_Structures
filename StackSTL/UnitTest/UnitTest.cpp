#include "pch.h"
#include "CppUnitTest.h"
#include "..\StackSTL\StackSTL.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(StackSTLTest)
	{
	public:
		
		TEST_METHOD(TestSize)
		{
			stack<int> stack;
			stack.push(3);
			Assert::AreEqual(stack.size(), (size_t)1);
			stack.push(31);
			Assert::AreEqual(stack.size(), (size_t)2);
			stack.pop();
			Assert::AreNotEqual(stack.size(), (size_t)4);
		}

		TEST_METHOD(TestEmpty)
		{
			stack<int> stack;
			stack.push(3);
			Assert::IsFalse(stack.empty());
			stack.pop();
			Assert::IsTrue(stack.empty());
		}

		TEST_METHOD(TestTop)
		{
			stack<int> stack;
			stack.push(3);
			Assert::AreEqual(stack.top(), 3);
			stack.push(31);
			Assert::AreEqual(stack.top(), 31);
			stack.push(5);
			Assert::AreNotEqual(stack.top(), 4);
		}
	};
}
