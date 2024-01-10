#include "pch.h"
#include "CppUnitTest.h"
#include "../Queue/Queue.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(TestQueue)
	{
	public:

		TEST_METHOD(TestPush)
		{
			Queue<int> qu;
			qu.push(4);
			qu.push(16);
			Assert::IsTrue(qu.size() == 2);
			qu.push(22);
			Assert::IsFalse(qu.size() == 4);
		}

		TEST_METHOD(TestPop)
		{
			Queue<int> qu;
			qu.push(4);
			qu.push(16);
			qu.push(22);
			qu.push(9);
			Assert::IsTrue(qu.size() == 4);
			qu.pop();
			qu.pop();
			Assert::IsTrue(qu.size() == 2);
			Assert::AreEqual(qu.front(), 22);
		}

		TEST_METHOD(TestEmpty)
		{
			Queue<int> qu;
			qu.push(4);
			qu.push(16);
			Assert::IsTrue(qu.size() == 2);
			qu.pop();
			qu.pop();
			Assert::IsTrue(qu.empty());
		}

		TEST_METHOD(TestFront)
		{
			Queue<int> qu;
			qu.push(4);
			qu.push(16);
			qu.push(22);
			qu.push(9);
			Assert::IsTrue(qu.front() == 4);
		}

		TEST_METHOD(TestBack)
		{
			Queue<int> qu;
			qu.push(4);
			qu.push(16);
			qu.push(22);
			qu.push(9);
			Assert::IsTrue(qu.back() == 9);
		}

		TEST_METHOD(TestSwap)
		{
			Queue<int> qu;
			qu.push(4);
			qu.push(16);
			qu.push(22);
			qu.push(9);
			Assert::IsTrue(qu.size() == 4);

			Queue<int> qu2;
			qu2.push(5);
			qu2.push(15);
			Assert::IsTrue(qu2.size() == 2);

			qu.swap(qu2);
			Assert::IsTrue(qu.size() == 2);
			Assert::IsTrue(qu2.size() == 4);
		}
	};

	TEST_CLASS(TestSTLQueue)
	{
	public:
		
		TEST_METHOD(TestPush)
		{
			queue<int> elem;
			elem.push(4);
			elem.push(14);
			elem.push(55);
			Assert::IsTrue(elem.size() == 3);
		}

		TEST_METHOD(TestPop)
		{
			queue<int> elem;
			elem.push(4);
			elem.push(14);
			elem.push(55);
			Assert::IsTrue(elem.size() == 3);
			elem.pop();
			elem.pop();
			Assert::IsFalse(elem.size() == 3);
		}

		TEST_METHOD(TestBack)
		{
			queue<int> elem;
			elem.push(4);
			elem.push(14);
			elem.push(55);
			Assert::AreEqual(elem.back(), 55);
		}

		TEST_METHOD(TestFront)
		{
			queue<int> elem;
			elem.push(4);
			elem.push(14);
			elem.push(55);
			Assert::AreEqual(elem.front(), 4);
			elem.pop();
			Assert::AreEqual(elem.front(), 14);
		}
	};
}
