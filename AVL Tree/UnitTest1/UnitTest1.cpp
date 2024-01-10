#include "pch.h"
#include "CppUnitTest.h"
#include "../AVL Tree/AVL.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(AVLTreeTest)
	{
	public:
		
		TEST_METHOD(TestCount)
		{
			Node* root = nullptr;
			AVLTree tree;

			root = tree.insert(root, 8);
			root = tree.insert(root, 10);
			root = tree.insert(root, 4);
			root = tree.insert(root, 2);
			root = tree.insert(root, 6);
			root = tree.insert(root, 1);

			Assert::IsTrue(tree.count == 6);
		}

		TEST_METHOD(TestInsert)
		{
			Node* root = nullptr;
			AVLTree tree;

			root = tree.insert(root, 8);
			root = tree.insert(root, 10);
			root = tree.insert(root, 4);
			root = tree.insert(root, 2);
			root = tree.insert(root, 6);
			root = tree.insert(root, 1);

			Assert::IsTrue(root->key == 4);
		}

		TEST_METHOD(TestHeight)
		{
			Node* root = nullptr;
			AVLTree tree;

			root = tree.insert(root, 8);
			root = tree.insert(root, 10);
			root = tree.insert(root, 4);
			root = tree.insert(root, 2);
			root = tree.insert(root, 6);
			root = tree.insert(root, 1);

			Assert::IsTrue(tree.height(root) == 3);
		}

		TEST_METHOD(TestdeleteNode)
		{
			Node* root = nullptr;
			AVLTree tree;

			root = tree.insert(root, 8);
			root = tree.insert(root, 10);
			root = tree.insert(root, 4);
			root = tree.insert(root, 2);
			root = tree.insert(root, 6);
			root = tree.insert(root, 1);

			tree.deleteNode(root, 4);

			Assert::IsTrue(root->key == 6);
		}

		TEST_METHOD(TestnewNode)
		{
			AVLTree tree;

			Node* root2 = tree.newNode(18);
			Node* root3 = tree.newNode(8);
			Node* root4 = tree.newNode(10);

			Assert::IsTrue(tree.count==3);
		}
	};
}
