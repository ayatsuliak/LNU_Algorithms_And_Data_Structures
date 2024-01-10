#include "pch.h"
#include "CppUnitTest.h"
#include "..\Stack\Stack.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(StackTest)
	{
	public:
		
		TEST_METHOD(TestPop)
		{
			Stack stack;
			stack.push(5);
			Assert::AreEqual(stack.pop(), 5);
			stack.push(10);
			Assert::AreNotEqual(stack.pop(), 9);
		}

		TEST_METHOD(TestPeek)
		{
			Stack stack;
			stack.push(77);
			Assert::AreEqual(stack.peek(), 77);
			stack.push(99);
			Assert::AreNotEqual(stack.peek(), 97);
		}

		TEST_METHOD(TestSize)
		{
			Stack stack;
			stack.push(77);
			Assert::AreEqual(stack.size(), 1);
			stack.push(99);
			Assert::AreEqual(stack.size(), 2);
			stack.push(5);
			Assert::AreNotEqual(stack.size(), 4);
		}

		TEST_METHOD(TestIsEmpty)
		{
			Stack stack;
			Assert::IsTrue(stack.isEmpty());
		}

		TEST_METHOD(TestIsFull)
		{
			Stack stack;
			stack.push(4);
			stack.push(55);
			stack.push(67);
			stack.push(1);
			stack.push(22);
			stack.push(3);
			stack.push(78);
			stack.push(1);
			stack.push(444);
			stack.push(66);
			Assert::IsTrue(stack.isFull());
		}
	};
}