#include "pch.h"
#include "CppUnitTest.h"
#include "..\Hash Table\HashTable.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(HashTableTest)
	{
	public:

		TEST_METHOD(TestTableSize)
		{
			TableElem* arr = new TableElem[2];
			arr[0] = { 'A', 20 };
			arr[1] = { 'B', 1 };
			HashTable table;
			table.AddRow(arr[0]);
			table.AddRow(arr[1]);
			Assert::AreEqual(table.TableSize(), 2);
		}

		TEST_METHOD(TestDeleteElement)
		{
			TableElem* arr = new TableElem[2];
			arr[0] = { 'A', 20 };
			arr[1] = { 'B', 1 };
			HashTable table1;
			table1.AddRow(arr[0]);
			table1.AddRow(arr[1]);
			Assert::AreEqual(table1.TableSize(), 2);
			table1.DeleteElement('B');
			Assert::AreNotEqual(table1.TableSize(), 2);
		}

		TEST_METHOD(TestIsEmpty)
		{
			TableElem* arr = new TableElem[3];
			arr[0] = { 'A', 20 };
			arr[1] = { 'B', 1 };
			arr[2] = { 'C', 4 };
			HashTable table2;
			Assert::IsTrue(table2.IsEmpty());
		}

		TEST_METHOD(TestFindByKey)
		{
			TableElem* arr = new TableElem[3];
			arr[0] = { 'A', 20 };
			arr[1] = { 'B', 1 };
			arr[2] = { 'C', 4 };
			HashTable table3;
			table3.AddRow(arr[0]);
			table3.AddRow(arr[1]);
			table3.AddRow(arr[2]);
			Assert::IsTrue(table3.FindByKey('B', arr[1]));
		}

		TEST_METHOD(TestSubstituteByKey)
		{
			TableElem* arr = new TableElem[4];
			arr[0] = { 'A', 20 };
			arr[1] = { 'B', 1 };
			arr[2] = { 'C', 4 };
			arr[3] = { 'A', 44 };
			HashTable table4;
			table4.AddRow(arr[0]);
			table4.AddRow(arr[1]);
			table4.AddRow(arr[2]);
			table4.SubstituteByKey('A', arr[3]);
			Assert::IsTrue(table4.FindByKey('A', arr[3]));
		}
	};
}
