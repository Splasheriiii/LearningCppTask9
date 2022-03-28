#include <iostream>
#include <random>
#include "TStack.cpp"

#include "Task91.cpp"

#define MIN 1
#define MAX 100
#define DELIMITER "----------------------------"

using namespace std;
/// <summary>
/// ��� - �����. ������������ �� ���� ���� ����� �����.
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
/// ����� ������� �� ������� ����� �����������
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
/// ������ ������� 5 � 9
/// </summary>
void task912()
{
	int i1 = 3, i2 = 5;
	int arr[] = { 3, 9, 5, 7 };
	std::cout << "Max int = " << get_max<int>(3, 5) << std::endl;
	std::cout << "Max int = " << get_max<int>(arr, 4) << std::endl;
}
/// <summary>
/// ������ ������� ������ ������, ��� ��� 's' > 'l'
/// </summary>
void task913()
{
	char* s1 = const_cast<char*>("String long");
	char* s2 = const_cast < char*>("String short");
	std::cout << "max str = " << get_max<char*>(s1, s2) << std::endl;
}
/// <summary>
/// �������� ����� �����.
/// ������� �����.
/// ���������� �����.
/// ������� �����.
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
/// size ��� ������������ ��������� ����� � �����
/// </summary>
/// <param name="size">������ ������ - ���������� �����</param>
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
/// ����������� �� ������ ��� ����� �� ��������� �����, ������� ������ �� � �������.
/// ����� �� ���������� ����� ��� ����� ������������� ������� � �������������� �����.
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
/// ��������� ���� � ������� ��������������� �����(������).
/// ������� �������� �����:
/// <para/>���� � �������������� ����� ������ ��� - ���������� ���� ���������� ����� �� ������ � �������� �����
/// <para/>���� � �������������� ����� ���-�� ����:
/// <para/>�������� ���������� ����� �� ������ � �������� �����
/// <para/>���� ��� ������ ����� �� ��������������� ����� - ������� ����� �� ��������������� ����� � �����
/// <para/>����� - ��������� ��������� ���������� ����� � �������������� ����
/// </summary>
/// <param name="in_train">���� ��� ����������</param>
/// <returns>��������������� ����</returns>
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
		///������������������ ������ ��� ������
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
/// ��������� ������� ����� �� ������ ������ � ������
/// </summary>
/// <param name="result">���� ��������� �����</param>
/// <param name="in_train">������ ��������� �����</param>
void train_transfer(Train* result, Train* in_train)
{
	result->push(in_train->pop());
}
/// <summary>
/// ������� ����� � ���������� ������� ������
/// </summary>
/// <returns>true ���� � ������ ������ ����������, false ���� �� ������ ����������</returns>
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