#include<iostream>
#include<cstdlib>

using namespace std;

struct TableElem
{
    char key;
    int value;
    TableElem()
    {
        key = '0';
        value = 0;
    }

    TableElem(char _key, int _value)
    {
        this->key = _key;
        this->value = _value;
    }

    bool operator==(TableElem tab_elem)
    {
        return this->key == tab_elem.key && this->value == tab_elem.value;
    }

    void print()
    {
        cout << "key: " << key << " " << "value: " << value << endl;
    }
};

class HashTable
{
private:
    int size = 10;
    TableElem* table = new TableElem[size];
    int empty_index = 0;  
    int GetHash(unsigned char key)
    {
        int hash;
        hash = key % size;
        return hash;
    }
public:
    HashTable()
    {

    }

    void AddRow(TableElem new_element)
    {
        empty_index++;
        if (IsFull())
        {
            IncreaseInSize();
        }
        int hash = GetHash(new_element.key);  //позиція, куди записуємо елем.
        int rehash = 0;
        while (table[(hash + rehash) % size].key != 0)  //перевіряємо чи немає за тим хешом якогось елем.
        {
            if (rehash == size)
            {
                break;
            }
            rehash++;
        }
        table[(hash + rehash) % size] = new_element;
    }

    bool FindByKey(char key, TableElem& found_element)
    {
        if (key == 0)
        {
            exit(EXIT_FAILURE);
        }
        bool found = false;
        int hash = GetHash(key);
        int rehash = 0;
        while (table[(hash + rehash) % size].key != key && table[(hash + rehash) % size].key != 0)
        {
            if (rehash == size)
            {
                break;
            }
            rehash++;
        }
        if (table[(hash + rehash) % size].key == key)
        {
            found_element = table[(hash + rehash) % size];
            found = true;
        }
        if (!found)
        {
            exit(EXIT_FAILURE);
        }
        return found;
    }

    int GetIndexByKey(char _key)
    {
        int return_value;
        for (int i = 0; i < empty_index; i++)
        {
            if (table[i].key == _key)
            {
                return_value = i + 1;
            }
        }
        return return_value;
    }

    int GetIndexByValue(char _value)
    {
        int return_value;
        for (int i = 0; i < empty_index; i++)
        {
            if (table[i].value == _value)
            {

                return_value = i + 1;
            }
        }
        return return_value;
    }

    void SubstituteByKey(char _key, TableElem& new_element)
    {
        for (int i = 0; i < empty_index; i++)
        {
            if (new_element.key == table[i].key)
            {
                table[GetIndexByKey(_key)] = new_element;
            }
            else
            {
                AddRow(new_element);
            }
        }
    }

    int TableSize()
    {
        int value_size = 0;
        for (int i = 0; i < empty_index; i++)
        {
            value_size++;
        }
        return value_size;
    }

    bool IsEmpty()
    {
        bool is_empty_value = false;
        if (TableSize() == 0)
        {
            is_empty_value = true;
        }
        return is_empty_value;
    }

    bool IsFull()
    {
        bool is_full_value = false;
        if (TableSize() == size)
        {
            is_full_value = true;
        }
        return is_full_value;
    }

    void IncreaseInSize()
    {
        if (IsFull() == true)
        {
            TableElem* bigger_table = new TableElem[size + 10];
            for (int i = 0; i < size; i++)
            {
                bigger_table[i] = table[i];
            }
            delete[] table;
            size += 10;
            table = bigger_table;
        }
    }

    void DeleteElement(char _key)
    {
        if (_key == 0)
        {
            exit(EXIT_FAILURE);
        }
        HashTable copy_of_table;
        for (int i = 0; i < size; i++)
        {
            if (table[i].key != 0)
            {
                if (table[i].key != _key)
                {
                    copy_of_table.AddRow(table[i]);
                }
            }
        }
        for (int i = 0; i < size; i++)
        {
            this->table[i] = copy_of_table.table[i];  
        }
        empty_index--;
    }

    void print()
    {
        for (int i = 0; i < empty_index; i++)
        {
            table[i].print();
        }
    }

    ~HashTable()
    {
        delete[] table;
    }
};

int main()
{
    return 0;
}