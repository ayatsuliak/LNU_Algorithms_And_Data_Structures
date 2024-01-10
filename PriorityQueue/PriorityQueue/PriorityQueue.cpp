#include<iostream>
#include<cstdlib>
#include<queue>

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
class PriorityQueue
{
private:
	Node<T>* head;
	Node<T>* tail;
public:
	PriorityQueue()
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
		else if (head->data <= _data)
		{
			temp->next = head;
			head->prev = temp;
			head = temp;
		}
		else if (tail->data >= _data)
		{
			temp->prev = tail;
			tail->next = temp;
			tail = temp;
		}
		else
		{
			Node<T>* node = head;
			while (node->data > _data)
			{
				node = node->next;
			}
			node->next = temp;
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

	T& top()
	{
		if (empty())
		{
			cout << "Queue is empty" << endl;
			exit(EXIT_FAILURE);
		}
		return head->data;
	}

	void swap(PriorityQueue& qu)
	{
		PriorityQueue temp = *this;
		*this = qu;
		qu = temp;
	}

	bool empty()
	{
		return head == nullptr;
	}

	size_t size()
	{
		PriorityQueue temp = *this;
		size_t value = 0;
		while (!temp.empty())
		{
			temp.pop();
			value++;
		}
		return value;
	}

	~PriorityQueue() {}
};

int main()
{
	priority_queue<int> element;
	int i = 0;
	cout << "Enter 3 elements: " << endl;
	while (i != 3)
	{
		int symbol;
		cin >> symbol;
		element.push(symbol);
		i++;
	}

	cout << "Element: ";
	while (!element.empty())
	{
		cout << element.top() << " ";
		element.pop();
	}
}