#include<iostream>
#include<string>

using namespace std;

//class CyclicQueue
//{
//private:
//	static const size_t ArraySize = 10;
//	char queue_container[ArraySize];
//	size_t head_index = 0;
//	size_t empty_index = 0;
//public:
//    unsigned int elements_quantity()
//    {
//        //todo: check!!!
//        return (empty_index - head_index + ArraySize) % ArraySize;
//    }
//
//    void enqueue(char new_element)
//    {
//        //todo: check empty space!!
//        queue_container[empty_index] = new_element;
//        empty_index = (empty_index + 1) % ArraySize;
//    }
//
//    char dequeue()
//    {
//        //todo: check if not empty
//        char return_value;
//        return_value = queue_container[head_index];
//        head_index = (head_index + 1) % ArraySize;
//    }
//
//};

class String
{
private:
    size_t size_of_array = 0;
    char* container_array = nullptr;
public:
    String()
    {

    }

    String(char* string)
    {
        size_of_array = strlen(string);
        container_array = new char[size_of_array];
        memcpy(container_array, string, size_of_array);
    }

    String(const String& other)
    {
        size_of_array = other.size_of_array;
        container_array = new char[size_of_array];
        memcpy(container_array, other.container_array, size_of_array);
    }

    String& operator+(const String& other)
    {
        String result;
        result=
    }


    ~String()
    {
        delete[] container_array;
    }
};



int main()
{
    cout << "Hello World";



    return 0;
}
