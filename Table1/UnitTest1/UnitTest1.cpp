#include "pch.h"
#include "CppUnitTest.h"
#include "..\Table1\Table.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(TableTest)
	{
	public:

		TEST_METHOD(TestTableSize)
		{
			TableElem* arr = new TableElem[2];
			arr[0] = { 'A', 20 };
			arr[1] = { 'B', 1 };
			Table table;
			table.AddRow(arr[0]);
			Assert::AreEqual(table.TableSize(), 1);
			table.AddRow(arr[1]);
			Assert::AreNotEqual(table.TableSize(), 3);
		}

		TEST_METHOD(TestFindByKey)
		{
			TableElem* arr = new TableElem[3];
			arr[0] = { 'A', 20 };
			arr[1] = { 'B', 1 };
			arr[2] = { 'C', 4 };
			const int size = 3;
			Table* table1 = new Table[size];
			table1[0].AddRow(arr[0]);
			table1[1].AddRow(arr[1]);
			table1[2].AddRow(arr[2]);
			Assert::IsTrue(table1->FindByKey('A', arr[0]));
			Assert::IsFalse(table1->FindByKey('H', arr[1]));
		}

		TEST_METHOD(TestGetIndexByKey)
		{
			TableElem* arr = new TableElem[2];
			arr[0] = { 'A', 20 };
			arr[1] = { 'B', 1 };
			Table table2;
			table2.AddRow(arr[0]);
			table2.AddRow(arr[1]);
			Assert::AreEqual(table2.GetIndexByKey('B'), 2);
		}

		TEST_METHOD(TestDeleteElement)
		{
			TableElem* arr = new TableElem[2];
			arr[0] = { 'A', 20 };
			arr[1] = { 'B', 1 };
			Table table3;
			table3.AddRow(arr[0]);
			table3.AddRow(arr[1]);
			Assert::AreEqual(table3.TableSize(), 2);
			table3.DeleteElement('A');
			Assert::AreEqual(table3.TableSize(), 1);
		}

		TEST_METHOD(TestIsEmpty)
		{
			TableElem* arr = new TableElem[3];
			arr[0] = { 'A', 20 };
			arr[1] = { 'B', 1 };
			arr[2] = { 'C', 4 };
			Table table4;
			Assert::IsTrue(table4.IsEmpty());
		}
	};
}
