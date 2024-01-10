#include <iostream>
#include <cstdlib>

#define SIZE 10

using namespace std;

class Stack
{
private:
	int* arr;
	int top;
	int capacity;  
public:
	Stack(int size = SIZE)
	{
		arr = new int[size];
		capacity = size;
		top = -1;
	}

	~Stack()
	{
		delete[] arr;
	}

	void push(int x)
	{
		if (isFull())
		{
			cout << "Stack overflow" << endl;
			exit(EXIT_FAILURE);
		}
		top++;
		arr[top] = x;
	}

	int pop()
	{
		if (isEmpty())
		{
			cout << "Stack underflow" << endl;
			exit(EXIT_FAILURE);
		}
		int to_return = arr[top];
		top--;
		return to_return;
	}

	int size()
	{
		return top + 1;
	}

	bool isFull()
	{
		return size() == capacity;
	}

	bool isEmpty()
	{
		return size() == 0;
	}

	int peek()
	{
		if (!isEmpty())
		{
			return arr[top];
		}
		else
		{
			exit(EXIT_FAILURE);  
		}
	}
};

//перевірити стек isEmpty, повернути true якщо все ок
bool stack_test1()
{
	bool test_passed = true;
	Stack stack1;
	test_passed = test_passed && stack1.isEmpty() == true;
	stack1.push(2);
	test_passed = test_passed && stack1.isEmpty() == false;
	stack1.pop();
	test_passed = test_passed && stack1.isEmpty() == true;
	return test_passed;
}

//перевірити стек push pop, повернути true якщо все ок
bool stack_test2()
{
	bool test_passed = true;
	Stack stack1;
	stack1.push(2);
	stack1.push(3);
	test_passed = test_passed && stack1.pop() == 3;
	test_passed = test_passed && stack1.pop() == 2;
	return test_passed;
}

bool stack_test3()
{
	bool test_passed = true;
	Stack stack1;
	stack1.push(2);
	stack1.push(3);
	test_passed = test_passed && stack1.peek() == 3;
	return test_passed;
}

//int main()
//{
//	int size = SIZE;
//	Stack* arr = new Stack[size];
//
//	cout << "\tStack program" << endl;
//	cout << "Test 1:" << (stack_test1() ? "passed" : "failed") << endl;
//	cout << "Test 2:" << (stack_test2() ? "passed" : "failed") << endl;
//	cout << "Test 3:" << (stack_test3() ? "passed" : "failed") << endl;
//
//	return 0;
//}
