#include "pch.h"
#include "CppUnitTest.h"
#include "../PriorityQueue/PriorityQueue.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(TestPriorityQueue)
	{
	public:
		
		TEST_METHOD(TestPush)
		{
			PriorityQueue<int> qu;
			qu.push(4);
			qu.push(16);
			Assert::IsTrue(qu.size() == 2);
			Assert::AreEqual(qu.top(), 16);
			qu.push(22);
			Assert::IsFalse(qu.size() == 4);
		}

		TEST_METHOD(TestPop)
		{
			PriorityQueue<int> qu;
			qu.push(16);
			qu.push(22);
			qu.push(9);
			Assert::IsTrue(qu.size() == 3);
			qu.pop();
			Assert::IsTrue(qu.size() == 2);
			Assert::AreEqual(qu.top(), 16);
		}

		TEST_METHOD(TestEmpty)
		{
			PriorityQueue<int> qu;
			qu.push(4);
			qu.push(16);
			Assert::IsTrue(qu.size() == 2);
			qu.pop();
			qu.pop();
			Assert::IsTrue(qu.empty());
		}

		TEST_METHOD(TestTop)
		{
			PriorityQueue<int> qu;
			qu.push(4);
			qu.push(16);
			qu.push(22);
			qu.push(9);
			Assert::IsTrue(qu.top() == 22);
		}

		TEST_METHOD(TestSwap)
		{
			PriorityQueue<int> qu;
			qu.push(4);
			qu.push(16);
			qu.push(22);
			qu.push(9);
			Assert::IsTrue(qu.size() == 4);

			PriorityQueue<int> qu2;
			qu2.push(5);
			qu2.push(15);
			Assert::IsTrue(qu2.size() == 2);

			qu.swap(qu2);
			Assert::IsTrue(qu.size() == 2);
			Assert::IsTrue(qu2.size() == 4);
		}
	};

	TEST_CLASS(TestSTLPriorityQueue)
	{
	public:

		TEST_METHOD(TestPush)
		{
			priority_queue<int> elem;
			elem.push(4);
			elem.push(14);
			elem.push(55);
			Assert::IsTrue(elem.size() == 3);
		}

		TEST_METHOD(TestPop)
		{
			priority_queue<int> elem;
			elem.push(4);
			elem.push(14);
			elem.push(55);
			Assert::IsTrue(elem.size() == 3);
			elem.pop();
			elem.pop();
			Assert::IsFalse(elem.size() == 3);
		}

		TEST_METHOD(TestTop)
		{
			priority_queue<int> elem;
			elem.push(4);
			elem.push(14);
			elem.push(55);
			Assert::AreEqual(elem.top(), 55);
			elem.pop();
			Assert::AreEqual(elem.top(), 14);
		}
	};
}
