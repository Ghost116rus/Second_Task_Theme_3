#include "My_List.h"

using namespace MYLIST;


void MYLIST::init(my_List& m_l, bool& init_complete)
{
	m_l.count = 0;
	init_complete = true;
}


void MYLIST::show(my_List& m_l)
{
	for (size_t i = 0; i < m_l.count; i++)
	{
		std::cout << i+1 << "-й\tэлемент списка. Данные: " << m_l.fix_arr[i] << std::endl;
	}
}


bool MYLIST::full(my_List& m_l)
{
	return (m_l.count == Array_size);
}


bool MYLIST::empty(my_List& m_l)
{
	return !(m_l.count);
}

/*
template< typename T>
int find(my_List<T>& m_l, int find_data, int condition)
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
			if (find_data < m_l.fix_arr[current_i])
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
*/



int MYLIST::find_v2(my_List& m_l, MyType find_data, const std::function<bool(MyType, MyType)>& fcn)
{
	for (int current_i = 0; current_i < m_l.count; current_i++)
	{
		if (fcn(find_data, m_l.fix_arr[current_i]))
		{
			return current_i;
		}
	}
	return Not_found;
}



void MYLIST::add(my_List& m_l, MyType data, const std::function<bool(MyType, MyType)>& fcn)
{
	//if (full(m_l))
	//{
	//	std::cout << "Список переполнен!\n";
	//	return;
	//}

	int current_i = find_v2(m_l, data, fcn);

	if (current_i != Not_found)
	{
		MyType temp = m_l.fix_arr[current_i];
		m_l.fix_arr[current_i++] = data;

		for (; current_i < m_l.count+1; current_i++)
		{
			data = m_l.fix_arr[current_i];
			m_l.fix_arr[current_i] = temp;
			temp = data;
		}
	}
	else
	{
		m_l.fix_arr[m_l.count] = data;
	}

	m_l.count++;
}


void MYLIST::remove(my_List& m_l, MyType data)
{
	//if (empty(m_l))
	//{
	//	std::cout << "Список переполнен!\n";
	//	return;
	//}

	int current_i = find_v2(m_l, data, [](MyType first, MyType second)
		{
			return first == second;
		}	
	);

	if (current_i != Not_found)
	{
		if (current_i == Array_size-1)
		{
			m_l.fix_arr[current_i] = 0; m_l.count--; return;
			//m_l.fix_arr[current_i] = ""; return;
		}

		for (; current_i < m_l.count; current_i++)
		{
			m_l.fix_arr[current_i] = m_l.fix_arr[current_i + 1];
		}
		m_l.count--;
	}
	else
	{
		std::cout << "Заданные данные не найдены!\n";
	}


}


