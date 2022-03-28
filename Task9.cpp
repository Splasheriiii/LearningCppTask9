#include <iostream>
#include <random>
#include "TStack.cpp"

#include "Task91.cpp"

#define MIN 1
#define MAX 100
#define DELIMITER "----------------------------"

using namespace std;
/// <summary>
/// Тип - поезд. Представляет из себя стек целых чисел.
/// </summary>
typedef TStack<int> Train;

void task912();
void task913();
void task93();
Train* create_rand_train(int);
void print_train(Train*);
Train* sort_train(Train*);
void train_transfer(Train*, Train*);
bool get_less_value(Train*, Train*);

/// <summary>
/// Вывод каждого из заданий через разделители
/// </summary>
/// <returns></returns>
int main()
{
	cout << "TASK 9.1.2" << endl;
	cout << DELIMITER << endl;
	task912();
	cout << DELIMITER << endl;
	cout << "TASK 9.1.3" << endl;
	cout << DELIMITER << endl;
	task913();
	cout << DELIMITER << endl;
	cout << "TASK 9.3" << endl;
	cout << DELIMITER << endl;
	task93();
}
/// <summary>
/// Должна вывести 5 и 9
/// </summary>
void task912()
{
	int i1 = 3, i2 = 5;
	int arr[] = { 3, 9, 5, 7 };
	std::cout << "Max int = " << get_max<int>(3, 5) << std::endl;
	std::cout << "Max int = " << get_max<int>(arr, 4) << std::endl;
}
/// <summary>
/// Должна вывести вторую строку, так как 's' > 'l'
/// </summary>
void task913()
{
	char* s1 = const_cast<char*>("String long");
	char* s2 = const_cast < char*>("String short");
	std::cout << "max str = " << get_max<char*>(s1, s2) << std::endl;
}
/// <summary>
/// Рандомно задаёт поезд.
/// Выводит поезд.
/// Сортитрует поезд.
/// Выводит поезд.
/// </summary>
void task93()
{
	Train* train = create_rand_train(11);
	cout << "Created train:" << endl << '\t';
	print_train(train);
	cout << DELIMITER << endl;
	train = sort_train(train);
	cout << "Sorted train:" << endl << '\t';
	print_train(train);

}
/// <summary>
/// size раз заталкиваеть рандомное число в поезд
/// </summary>
/// <param name="size">размер поезда - количество чисел</param>
/// <returns></returns>
Train* create_rand_train(int size)
{
	Train* res = new Train();
	for (int i = 0; i < size; i++)
	{
		int num = MIN + (rand() % (MAX - MIN + 1));
		res->push(num);
	}
	return res;
}

/// <summary>
/// Выталкивает из поезда все числа во временный поезд, попутно выводя их в консоль.
/// Затем из временного поеза все числа заталкиваются обратно в первоначальный поезд.
/// </summary>
/// <param name="train"></param>
void print_train(Train* train)
{
	Train* temp_train = new Train();
	bool res_marker = (train->count() > 0);
	cout << "START\t";
	while (res_marker)
	{
		int number = train->try_pop(&res_marker);
		if (res_marker)
		{
			cout << number << '\t';
			temp_train->push(number);
		}
	}
	cout << "END" << endl;


	res_marker = true;
	while (res_marker)
	{
		int number = temp_train->try_pop(&res_marker);
		if (res_marker)
		{
			train->push(number);
		}
	}
}
/// <summary>
/// Сортирует стек с помощью дополнительного стека(тупика).
/// Порядок действий такой:
/// <para/>Если в результируещем стеке ничего нет - записываем туда наименьшее число из тупика и входного стека
/// <para/>Если в результируещем стеке что-то есть:
/// <para/>Выбираем наименьшее число из тупика и входного стека
/// <para/>Если оно меньше числа из результируещего стека - выводим число из результирующего стека в тупик
/// <para/>Иначе - добавляем выбранное наименьшее число в результирующий стек
/// </summary>
/// <param name="in_train">стек для сортировки</param>
/// <returns>отсортированный стек</returns>
Train* sort_train(Train* in_train)
{
	Train* result = new Train();
	Train* dead_end = new Train();
	while (in_train->count() > 0 || dead_end->count() > 0)
	{
		if (result->count() == 0)
		{
			train_transfer(result, get_less_value(in_train, dead_end) ? in_train : dead_end);
		}
		else
		{
			Train* less_train = get_less_value(in_train, dead_end) ? in_train : dead_end;
			if (get_less_value(less_train, result))
			{
				train_transfer(dead_end, result);
			}
			else
			{
				train_transfer(result, less_train);
			}
		}
		///Закомментированные строки для дебага
		/*cout << "First train:" << endl << '\t';
		print_train(in_train);
		cout << "Dead end:" << endl << '\t';
		print_train(dead_end);
		cout << "Sorted train:" << endl << '\t';
		print_train(result);
		cout << DELIMITER << endl;*/
	}
	delete dead_end;
	return result;
}
/// <summary>
/// Переводит верхнее число из одного поезда в другой
/// </summary>
/// <param name="result">Куда перенести число</param>
/// <param name="in_train">Откуда перенечти число</param>
void train_transfer(Train* result, Train* in_train)
{
	result->push(in_train->pop());
}
/// <summary>
/// Выбрать поезд с наименьшим верхним числом
/// </summary>
/// <returns>true если в первом поезде наименьшее, false если во втором наименьшее</returns>
bool get_less_value(Train* first_train, Train* second_train)
{
	if (first_train->count() > 0)
	{
		return (second_train->count() == 0) || (first_train->peek() < second_train->peek());
	}
	else
	{
		return false;
	}
}