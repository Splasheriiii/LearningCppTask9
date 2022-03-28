#include "TStack.h"
#include <cstring>

template<class T>
/// <summary>
/// �����������. ������������� ��������� ������ � 10. ����������� ������ � -1. ������ ������ �� 10 �����.
/// </summary>
TStack<T>::TStack()
{
	this->size = 10;
	current_index = -1;
	items = new T[size];
}
template<class T>
/// <summary>
/// ����������, ������������ ������, ������� ��������
/// </summary>
TStack<T>::~TStack()
{
	delete[] items;

}
/// <summary>
/// ���� � ������� ���������� ����� - ������ ����������� ������� ������ � ��������� ����� ������� � ����.
/// <para/> ����� �������� ����� ������, ��������� �����������, ���� ���������� ������ ������ � ��� ����� ������������� ������� ������ � ������������ ����� �������
/// <para/> ������ ��� ������ ������ ��������������.
/// </summary>
/// <param name="t">������� ��� �������</param>
template<class T>
void TStack<T>::push(T t)
{
	if (size == (current_index + 1))
	{
		size *= 2;
		T* old_array = items;
		T* new_array = new T[size];
		memcpy(new_array, old_array, (current_index + 1) * sizeof(T));
		items = new_array;
		delete[] old_array;
	}
	items[++current_index] = t;
}
/// <summary>
/// �������� ������� �� �������� �������, ����� ��������� ���� ������ �� 1
/// </summary>
/// <returns>������� �� �������� �������</returns>
template<class T>
T TStack<T>::pop()
{
	return items[current_index--];
}
template<class T>
/// <summary>
/// ���� ������� ������ < 0 - ������������� res_marker � false � ���������� NULL
/// <para/> ����� ������������� res_marker � true, �������� ������� �� �������� �������, ����� ��������� ���� ������ �� 1
/// </summary>
/// <returns>������� �� �������� �������</returns>
T TStack<T>::try_pop(bool* res_marker)
{
	*res_marker = (current_index >= 0);
	return (*res_marker) ? pop() : NULL;
}
/// <summary>
/// �������� ������� �� �������� �������, �� �������� ������� ������
/// </summary>
/// <returns>������� �� �������� �������</returns>
template<class T>
T TStack<T>::peek()
{
	return items[current_index];
}
/// <summary>
/// ���������� ���������� �������� ���������, � �� �����������.
/// </summary>
/// <returns>���������� ��������� � �����</returns>
template<class T>
int TStack<T>::count()
{
	return current_index + 1;
}