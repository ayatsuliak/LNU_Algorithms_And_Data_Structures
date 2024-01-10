#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

template<typename T>
struct Node
{
	Node* next;
	Node* prev;
	T data;
	Node(T data = T(), Node* p_next = nullptr, Node* p_prev = nullptr)
	{
		this->data = data;
		this->next = p_next;
		this->prev = p_prev;
	}
};

template<typename T>
class Queue
{
private:
	Node<T>* head;
	Node<T>* tail;
public:
	Queue()
	{
		this->head = nullptr;
		this->tail = nullptr;
	}

	void push(T _data)
	{
		Node<T>* temp = new Node<T>(_data);
		if (head == nullptr)
		{
			temp->prev = nullptr;
			head = tail = temp;
		}
		else
		{
			temp->prev = tail;
			tail->next = temp;
			tail = temp;
		}
	}

	void pop()
	{
		if (empty())
		{
			cout << "Queue is empty" << endl;
			exit(EXIT_FAILURE);
		}
		head = head->next;
		if (head != nullptr)
		{
			head->prev = nullptr;
		}
	}

	T& front()
	{
		if (empty())
		{
			cout << "Queue is empty" << endl;
			exit(EXIT_FAILURE);
		}
		return head->data;
	}

	T& back()
	{
		if (empty())
		{
			cout << "Queue is empty" << endl;
			exit(EXIT_FAILURE);
		}
		return tail->data;
	}

	void swap(Queue& qu)
	{
		Queue temp = *this;
		*this = qu;
		qu = temp;
	}

	bool empty()
	{
		return head == nullptr;
	}

	size_t size()
	{
		Queue temp = *this;
		size_t value = 0;
		while (!temp.empty())
		{
			temp.pop();
			value++;
		}
		return value;
	}

	~Queue(){}
};

int main()
{
	queue<int> numbers;
	int i = 0;
	cout << "Enter 3 elements: " << endl;
	while (i != 3)
	{
		int number;
		cin >> number;
		numbers.push(number);
		i++;
	}

	if (numbers.empty())
	{
		cout << "The stack is empty" << endl;
	}
	else
	{
		cout << "The stack is not empty" << endl;
	}
	cout << "The stack size is " << numbers.size() << endl;

	cout << "Back element: " << numbers.back() << endl;
	cout << "Let us delete the back element" << endl;

	cout << "Front element: " << numbers.front() << endl;

	numbers.pop();
	numbers.pop();
	cout << "The stack size is " << numbers.size() << endl;
	if (numbers.empty())
	{
		cout << "The stack is empty" << endl;
	}
	else
	{
		cout << "The stack is not empty" << endl;
	}

	return 0;
}