#include "pch.h"
#include "CppUnitTest.h"
#include "../Set/Set.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(TestSet)
	{
	public:

		TEST_METHOD(TestIsInSet)
		{
			Set st;
			Assert::IsFalse(st.IsInSet('a'));
			st.Add('a');
			Assert::IsTrue(st.IsInSet('a'));
		}
		
		TEST_METHOD(TestAddAndRemove)
		{
			Set st;
			st.Add('a');
			Assert::IsTrue(st.IsInSet('a'));
			st.Add('d');
			Assert::IsTrue(st.IsInSet('d'));
			st.Remove('a');
			Assert::IsFalse(st.IsInSet('a'));
			Assert::IsTrue(st.IsInSet('d'));
		}

		TEST_METHOD(TestUnion)
		{
			Set a;
			Set b;
			Set c;

			a.Add('a');
			a.Add('d');
			a.Add('f');

			b.Add('e');
			b.Add('f');

			c = a.Union(b);
			Assert::IsTrue(c.IsInSet('a'));
			Assert::IsTrue(c.IsInSet('d'));
			Assert::IsTrue(c.IsInSet('f'));
			Assert::IsTrue(c.IsInSet('e'));
		}

		TEST_METHOD(TestIntersect)
		{
			Set a;
			Set b;
			Set c;

			a.Add('a');
			a.Add('d');
			a.Add('f');

			b.Add('e');
			b.Add('f');

			c = a.Intersect(b);
			Assert::IsTrue(c.IsInSet('f'));
			Assert::IsFalse(c.IsInSet('a'));
			Assert::IsFalse(c.IsInSet('d'));			
			Assert::IsFalse(c.IsInSet('e'));
		}

		TEST_METHOD(TestDifference)
		{
			Set a;
			Set b;
			Set c;

			a.Add('a');
			a.Add('e');
			a.Add('f');

			b.Add('a');
			b.Add('b');

			c = a.Difference(b);
			Assert::IsFalse(c.IsInSet('a'));
			Assert::IsTrue(c.IsInSet('e'));
			Assert::IsTrue(c.IsInSet('f'));
		}
	};
}
