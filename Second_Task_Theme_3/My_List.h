#pragma once
#include <iostream>
#include <functional>

using MyType = int;

enum MyEnum
{
	Not_found = -1,
	Find_el,
};


namespace MYLIST
{
	const int Array_size = 10;

	struct my_List
	{
		int count;
		MyType fix_arr[Array_size]{};
	};

	void init(my_List& m_l, bool& init_complete);

	void show(my_List& m_l);

	bool full(my_List& m_l);

	bool empty(my_List& m_l);

	int find_v2(my_List& m_l, MyType find_data, const std::function<bool(MyType, MyType)>& fcn);

	void add(my_List& m_l, MyType data, const std::function<bool(MyType, MyType)>& fcn);

	void remove(my_List& m_l, MyType data);
}

