#include "user_interface.h"

template<typename T>
T getValue(int condition, const char* string)
{
	while (true)													// цикл продолжается до тех пор, пока пользователь не введет корректное значение
	{
		T a;
		std::cin >> a;

		if (std::cin.fail())										// если предыдущее извлечение оказалось неудачным,
		{
			std::cout << "Ошибка! Пожалуйста, повторите ввод! \n";
			std::cin.clear();										// то возвращаем cin в 'обычный' режим работы
			std::cin.ignore(32767, '\n');							// и удаляем значения предыдущего ввода из входного буфера
			std::cout << string;
		}
		else // если всё хорошо и выполнятся условия, то возвращаем a
		{
			switch (condition)
			{

			//case O_Or_1:												// На будущее

			//	if ((int)a == 0 || (int)a == 1) { return a; }

			//	std::cout << "Вы должны ввести либо 0, либо 1\n";
			//	std::cin.ignore(32767, '\n');						// и удаляем значения предыдущего ввода из входного буфера
			//	continue;

			//case Menu_Commands:

			//	if (((int)a > 0) && ((int)a < 8)) { return a; }

			//	std::cout << "У меню всего 7 функций! Повторите ввод: ";
			//	std::cin.ignore(32767, '\n');						// и удаляем значения предыдущего ввода из входного буфера
			//	continue;

			default:
				return a;
			}

		}

	}
}

void show_main_menu()
{
	std::cout << "  Функционал программы:\n"
		<< "1. Инициализация списка\n"
		<< "2. Добавление нового элемента\n"
		<< "3. Удаление элемента списка\n"
		<< "4. Показать содержимое списка\n"
		<< "5. Показать главное меню\n"
		<< "6. Вывести автора программы\n"
		<< "\n7. Завершение работы\n\n";
}

void write_author()
{
	std::cout << "Работу выполнил Калеев Д.А., группа 4211\n";
}

void start()
{
	std::string user_opinion;
	//std::cout << "Список с какими типом данных вы хотели бы создать: ";

	MYLIST::my_List<int> my_list; menu<int>(my_list);


}

template<typename T>
void menu(MYLIST::my_List<int>& my_list)
{
	int user_choice = 0;
	bool complete_init = false;

	show_main_menu();
	std::cout << "Выберите команду: ";
	user_choice = getValue<int>(Menu_Commands, "Выберите команду: ");

	while (user_choice != Exit)
	{
		T temp_data;
		switch (user_choice)
		{			

		case Init_stack:

			if (!complete_init)
			{
				MYLIST::init(my_list, complete_init);
			}
			else
			{
				std::cout << "Cписок уже инициализирован!\n";
			}
			break;

		case Add_new_element:

			if (complete_init)
			{
				std::cout << "Введите данные: "; temp_data = getValue<T>(1, "Введите данные: ");
				//MYLIST::add<T>(my_list, temp_data, [](T first, T second)
				//	{
				//		return first < second;
				//	}
				//);
			}
			else
			{
				std::cout << "Невозможно выполнить операцию, т.к список не инициализирован\n";
			}

			break;

		case Delete_last_element:

			if (complete_init)
			{
				temp_data = getValue<T>(1, "Введите данные: ");
				//MYLIST::remove<T>(my_list, temp_data);
			}
			else
			{
				std::cout << "Невозможно что-либо удалить, т.к список пустой!\n";
			}

			
			break;

		case Show_stack:

			if (complete_init) { //MYLIST::show<T>(my_list);
			}
			else { std::cout << "Список не инициализирован!\n"; }

			break;

		case Show_main_menu:

			std::cout << "\n\n";
			show_main_menu();
			break;

		case Write_author:

			write_author();
			break;

		default:
			break;
		}
		std::cout << "\nВыберите команду: ";
		user_choice = getValue<int>(Menu_Commands, "Выберите команду: ");
	}

	std::cout << "Завершение работы\n";
}