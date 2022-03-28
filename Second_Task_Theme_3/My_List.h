#pragma once
#include <iostream>
#include <functional>



enum MyEnum
{
	Not_found = -1,
	Find_el,
};


namespace MYLIST
{
	const int Array_size = 10;

	template< typename T>
	struct my_List
	{
		int count;
		T fix_arr[Array_size]{};
	};


	template< typename T>
	void init(my_List<T>& m_l, bool& init_complete);


	template< typename T>
	void show(my_List<T>& m_l);


	template< typename T>
	bool full(my_List<T>& m_l);


	template< typename T>
	bool empty(my_List<T>& m_l);


	/*
	template< typename T>
	int find(my_List<T>& m_l, int find_data, int condition);
	*/


	/// <summary>
	/// ������� ������ ������� ��������, ������� ������ ���������
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="m_l"> ��������� ������ </param>
	/// <param name="find_data"> ����� ������, ������ ��������� </param>
	/// <param name="fcn"> ������ ������� </param>
	/// <returns></returns>
	template< typename T>
	int find_v2(my_List<T>& m_l, T find_data, std::function<bool(T, T)>& fcn);


	/// <summary>
	/// ��������� ������� � ������ ����� � ������
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="m_l"> ��������� ������ </param>
	/// <param name="data"> ������ </param>
	template< typename T>
	void add(my_List<T>& m_l, T data, std::function<bool(T, T)>& fcn);

	template< typename T>
	void remove(my_List<T>& m_l, T data);
}

