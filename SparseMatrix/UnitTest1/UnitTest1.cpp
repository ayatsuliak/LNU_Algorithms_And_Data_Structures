#include "pch.h"
#include "CppUnitTest.h"
#include "..\SparseMatrix\SparseMatrixcpp.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(MatrixTest)
	{
	public:
		
		TEST_METHOD(TestSetValue)
		{
			SparseMatrix matrix(2, 2);
			matrix.SetValue(1, 2, 4);
			matrix.SetValue(2, 2, 15);
			Assert::IsTrue(matrix.GetValue(2, 2) == 15);
			Assert::IsFalse(matrix.GetValue(2, 2) == 5);
		}

		TEST_METHOD(TestOperatorAdd)
		{
			SparseMatrix matrix1(2, 2);
			matrix1.SetValue(1, 2, 4);
			matrix1.SetValue(1, 1, 15);

			SparseMatrix matrix2(2, 2);
			matrix2.SetValue(1, 2, 14);
			matrix2.SetValue(1, 1, 4);

			SparseMatrix matrix3(2, 2);
			matrix3 = matrix1 + matrix2;
			
			Assert::IsTrue(matrix3.GetValue(1, 2) == 18);
			Assert::IsFalse(matrix3.GetValue(1, 1) == 20);
		}

		TEST_METHOD(TestOperatorMultiply)
		{
			SparseMatrix matrix1(2, 3);
			matrix1.SetValue(1, 2, 5);
			matrix1.SetValue(2, 1, 15);
			matrix1.SetValue(1, 1, 8);

			SparseMatrix matrix2(3, 2);
			matrix2.SetValue(2, 1, 6);
			matrix2.SetValue(1, 1, 2);
			matrix2.SetValue(2, 2, 16);

			SparseMatrix matrix3(2, 2);
			matrix3 = matrix1 * matrix2;

			Assert::IsTrue(matrix3.GetValue(1, 1) == 46);
			Assert::IsFalse(matrix3.GetValue(1, 2) == 25);
		}
	};
}
