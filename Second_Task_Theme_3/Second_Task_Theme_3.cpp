// Second_Task_Theme_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>

const int size = 10;

enum MyEnum
{
	Not_found,
	Find_el,
	Find_el_who_more,

};


struct my_List
{
	int count;
	int fix_arr[size]{};
};

void init(my_List& m_l)
{
	m_l.count = 0;
}

void show(my_List& m_l)
{
	for (size_t i = 0; i < m_l.count; i++)
	{
		std::cout << i << "-й\tэлемент списка. Данные: " << m_l.fix_arr[i] << std::endl;
	}
}

bool full(my_List& m_l)
{
	return m_l.count == size;
}

int find(my_List& m_l, int find_data, int condition)
{
	switch (condition)
	{
	case Find_el:

		for (int current_i = 0; current_i < m_l.count; current_i++)
		{
			if (find_data == m_l.fix_arr[current_i])
			{
				return current_i;
			}
		}

		break;

	case Find_el_who_more:

		for (int current_i = 0; current_i < m_l.count; current_i++)
		{
			if (find_data > m_l.fix_arr[current_i])
			{
				return current_i;
			}
		}
		break;
	default:
		return Not_found;
		break;
	}
	return Not_found;
}


void add(my_List& m_l, int data, int condition)
{

	if (full(m_l))
	{
		std::cout << "Список переполнен!\n";
		return;
	}

	int current_i = find(m_l, data, Find_el_who_more);


	if (current_i)
	{

		int temp = m_l.fix_arr[current_i];
		m_l.fix_arr[current_i++] = data;

		for (; current_i < m_l.count; current_i++)
		{
			data = m_l.fix_arr[current_i];
			m_l.fix_arr[current_i] = temp;
			temp = data;
		}
	}
	else
	{
		m_l.fix_arr[m_l.count - 1] = data;
	}

	m_l.count++;
}



int main()
{
	setlocale(LC_ALL, "ru");



}

