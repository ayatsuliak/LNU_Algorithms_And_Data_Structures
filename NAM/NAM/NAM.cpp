#include <iostream>
#include <cstring>
#include<vector>
#include<cstdlib>

using namespace std;

template<typename String>
struct Markov
{
	vector <pair<String, String>>rules;

	Markov(size_t index)
	{
		if (index == 1)
		{
			rules.push_back(make_pair("1", "0|"));
			rules.push_back(make_pair("|0", "0||"));
			rules.push_back(make_pair("0", ""));
		}

		if (index == 2)
		{
			rules.push_back(make_pair("|b", "ba|"));
			rules.push_back(make_pair("ab", "ba"));
			rules.push_back(make_pair("b", ""));
			rules.push_back(make_pair("*|", "b*"));
			rules.push_back(make_pair("*", "c"));
			rules.push_back(make_pair("|c", "c"));
			rules.push_back(make_pair("ac", "c|"));
			rules.push_back(make_pair("c", "."));
		}

		if (index == 3)
		{
			rules.push_back(make_pair("ab", "b"));
			rules.push_back(make_pair("ac", "c"));
			rules.push_back(make_pair("aa", "a"));
		}
	}
};

class String
{
	size_t size_of_array = 0;
	char* container_array = nullptr;
public:
	String(){}

	String(const char* string)
	{
		size_of_array = strlen(string);
		//container_array <- string
		container_array = new char[size_of_array];
		memcpy(container_array, string, size_of_array);
	}

	String(const String& other)
	{
		*this = other;
	}

	String& operator=(const String& other)
	{
		delete[] container_array;
		size_of_array = other.size_of_array;
		container_array = new char[size_of_array];
		memcpy(container_array, other.container_array, size_of_array);
		return *this;
	}

	String operator+(const String& other)
	{
		String result;
		result.size_of_array = this->size_of_array + other.size_of_array;
		result.container_array = new char[result.size_of_array];
		//copy this and then other
		memcpy(result.container_array, this->container_array, this->size_of_array);
		memcpy(&result.container_array[this->size_of_array], other.container_array, other.size_of_array);
		return result;
	}

	friend ostream& operator<<(ostream& os, const String& str)
	{
		for (size_t i = 0; i < str.size_of_array; i++)
		{
			os << str.container_array[i];
		}
		return os;
	}

	bool operator==(const String& other)
	{
		bool are_equal;
		are_equal = this->size_of_array == other.size_of_array;
		if (are_equal)
		{
			for (int i = 0; (i < size_of_array) && are_equal; i++)
			{
				are_equal = this->container_array[i] == other.container_array[i];
			}
		}
		return are_equal;
	}

	size_t SizeOfArray() const
	{
		return size_of_array;
	}

	String Substring(size_t position, size_t length)
	{
		String result;
		result.size_of_array = length;
		result.container_array = new char[length];
		for (int i = 0; i < length; i++)
		{
			result.container_array[i] = container_array[i + position];
		}
		return result;
	}

	//returns (size_t)-1 if not found
	size_t find(const String& substring)
	{
		size_t position = -1;
		if (size_of_array >= substring.size_of_array)
		{
			size_t last_index_to_check = size_of_array - substring.size_of_array;
			for (size_t i = 0; i <= last_index_to_check; i++)
			{
				size_t j;
				bool still_equal = false;
				for (j = 0; j < substring.size_of_array; j++)
				{
					if (container_array[i + j] != substring.container_array[j])
					{
						still_equal = false;
						break;
					}
					still_equal = true;
				}
				//if substring found
				if (still_equal)
				{
					position = i;
					break;
				}
			}
		}
		return position;
	}

	String Replace(const String& from, const String& to)
	{
		size_t position_from = this->find(from);
		if (position_from != -1)
		{
			String before = this->Substring(0, position_from);
			size_t pos_from = position_from + from.SizeOfArray();
			size_t length_of_substring = this->SizeOfArray() - (position_from + from.SizeOfArray());
			String after = this->Substring(pos_from, length_of_substring);
			*this = before + to + after;
		}
		return *this;
	}

	String MarkAlg(const Markov<String>& rule)
	{
		for(size_t i = 0; i < rule.rules.size();)
		{
			if (find(rule.rules[i].first) != -1)
			{
				String to_what = rule.rules[i].second;
				Replace(rule.rules[i].first, to_what);
				i = 0;
			}
			else
			{
				++i;
			}
		}
		return *this;
	}

	~String()
	{
		size_of_array = 0;
		delete[] container_array;
	}
};

int main()
{
	String str = "1010";
	Markov<String> mark1(1);	
	cout << str.MarkAlg(mark1) << endl;

	str = "|*|||";
	Markov<String> mark3(2);
	cout << str.MarkAlg(mark3) << endl;

	return 0;
}