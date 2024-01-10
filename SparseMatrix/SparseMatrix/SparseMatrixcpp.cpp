#include<iostream>
#include<vector>

using namespace std;

struct Element
{
	Element* upper_element = this;
	Element* left_element = this;
	size_t row = 0;
	size_t column = 0;
	double value;
};

class SparseMatrix
{
private:
	size_t rows_count;
	size_t cols_count;
	vector<Element> cols;
	vector<Element> rows;

	Element* GetPriviousByRow(size_t row, size_t column)
	{
		Element* priv = &rows[row];
		while (priv->left_element->column > column)
		{
			priv = priv->left_element;
		}
		return priv;
	}

	Element* GetPriviousByCol(size_t row, size_t column)
	{
		Element* priv = &cols[column];
		while (priv->upper_element->row > row)
		{
			priv = priv->upper_element;
		}
		return priv;
	}

	void ChangeValue(Element* previous_by_row, Element* previous_by_col, size_t row, size_t column, double value)
	{
		if (value == 0)
		{
			Element* elem_to_del = previous_by_row->left_element;
			previous_by_row->left_element = elem_to_del->left_element;
			previous_by_col->upper_element = elem_to_del->upper_element;
			delete elem_to_del;
		}
		else
		{
			previous_by_row->left_element->value = value;
		}
	}

	void AddValue(Element* previous_by_row, Element* previous_by_col, size_t row, size_t column, double value)
	{
		Element* new_element = new Element();
		new_element->row = row;
		new_element->column = column;
		new_element->value = value;
		new_element->left_element = previous_by_row->left_element;
		previous_by_row->left_element = new_element;
		new_element->upper_element = previous_by_col->upper_element;
		previous_by_col->upper_element = new_element;
	}
public:
	SparseMatrix(size_t _rows_count, size_t _cols_count)
	{
		this->rows_count = _rows_count;
		this->cols_count = _cols_count;
		cols.resize(cols_count + 1);  //не використовується нульовий індекс
		rows.resize(rows_count + 1);
	}

	void SetValue(size_t row, size_t column, double value)
	{
		//беремо елементи попередній по колонці і рядку
		Element* previous_by_row = GetPriviousByRow(row, column);
		Element* previous_by_col = GetPriviousByCol(row, column);
		//чи є елемент в матриці
		bool element_in_matrix = previous_by_col->upper_element->row == row && previous_by_col->upper_element->column == column;
		//якщо елемент є в матриці, то ми або змінюємо, або додаємо
		if (element_in_matrix)
		{
			ChangeValue(previous_by_row, previous_by_col, row, column, value);
		}
		else
		{
			AddValue(previous_by_row, previous_by_col, row, column, value);
		}
	}

	double GetValue(size_t row, size_t column)
	{
		double ret_value = 0;
		Element* previous_by_col = GetPriviousByCol(row, column);
		bool element_in_matrix = previous_by_col->upper_element->row == row && previous_by_col->upper_element->column == column;
		if (element_in_matrix)
		{
			ret_value = previous_by_col->upper_element->value;
		}
		return ret_value;
	}

	SparseMatrix operator+(SparseMatrix& matrix)
	{
		if (this->rows_count != matrix.rows_count || this->cols_count != matrix.cols_count)
		{
			throw exception("These matrix do not match to add");
		}
		SparseMatrix result(this->rows_count, this->cols_count);
		for (size_t i = 1; i <= result.rows_count; i++)
		{
			for (size_t j = 1; j <= result.cols_count; j++)
			{
				double value = this->GetValue(i, j) + matrix.GetValue(i, j);
				result.SetValue(i, j, value);
			}
		}
		return result;
	}

	SparseMatrix operator*(SparseMatrix& matrix)
	{
		if (this->cols_count != matrix.rows_count)
		{
			throw exception("These matrix do not match for multiplication");
		}
		SparseMatrix result(this->rows_count, matrix.cols_count);
		for (size_t i = 1; i <= result.rows_count; i++)
		{
			for (size_t j = 1; j <= result.cols_count; j++)
			{
				double value = 0;
				for (size_t k = 1; k <= result.cols_count; k++)
				{
					value += this->GetValue(i, k) * matrix.GetValue(k, j);
				}
				result.SetValue(i, j, value);
			}
		}
		return result;
	}

	void print()
	{
		for (size_t i = 1; i <= this->rows_count; i++)
		{
			for (size_t j = 1; j <= this->cols_count; j++)
			{
				cout << this->GetValue(i, j) << " ";
			}
			cout << endl;
		}
	}
};

int main()
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

	try
	{
		matrix3 = matrix1 * matrix2;
		matrix3.print();
	}
	catch(exception& ex)
	{
		cout << ex.what() << endl;
	}

	try
	{
		matrix3 = matrix1 + matrix2;
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}

	return 0;
}