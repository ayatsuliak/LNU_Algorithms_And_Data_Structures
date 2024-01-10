#include<iostream>

using namespace std;

class Set
{
private:
	static const size_t arr_size = 8;  
	size_t container[arr_size] = { 0 };
	size_t GetPosition(char elem)
	{
		return (elem % 32);
	}
	size_t GetIndex(char elem)  //в €кий контейнер записувати
	{
		return (elem / 32);
	}
	size_t GetMask(char elem)
	{
		return (1 << GetPosition(elem));
	}
public:
	void Add(char elem)
	{
		container[GetIndex(elem)] = container[GetIndex(elem)] | GetMask(elem);
	}
	void Remove(char elem)
	{
		container[GetIndex(elem)] = container[GetIndex(elem)] & (~GetMask(elem));
	}
	bool IsInSet(char elem)
	{
		return (container[GetIndex(elem)] & GetMask(elem)) != 0;
	}
	Set Union(const Set& other)  //об'Їднанн€
	{
		Set to_return;
		for (size_t i = 0; i < arr_size; i++)
		{
			to_return.container[i] = this->container[i] | other.container[i];
		}
		return to_return;
	}
	
	Set Intersect(const Set& other)  //перетин
	{
		Set to_return;
		for (size_t i = 0; i < arr_size; i++)
		{
			to_return.container[i] = this->container[i] & other.container[i];
		}
		return to_return;
	}
	Set Difference(const Set& other)  //р≥зниц€
	{
		Set to_return;
		for (size_t i = 0; i < arr_size; i++)
		{
			to_return.container[i] = (this->container[i] ^ other.container[i]) & this->container[i];
		}
		return to_return;
	}
};

int main()
{
	return 0;
}