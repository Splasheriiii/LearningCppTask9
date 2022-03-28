#include "TStack.h"
#include <cstring>

template<class T>
/// <summary>
/// Конструктор. Устанавливает начальный размер в 10. Изначальный индекс в -1. Создаёт массив на 10 чисел.
/// </summary>
TStack<T>::TStack()
{
	this->size = 10;
	current_index = -1;
	items = new T[size];
}
template<class T>
/// <summary>
/// Деструктор, высвобождает память, занятую массивом
/// </summary>
TStack<T>::~TStack()
{
	delete[] items;

}
/// <summary>
/// Если в массиве достаточно места - просто увеличивает текущий индекс и добавляет новый элемент в него.
/// <para/> Иначе создаётся новый массив, удвоенной вместимости, туда копируется старый массив и уже потом увеличивается текущий индекс и добюавляется новый элемент
/// <para/> Память под старый массив высвобождается.
/// </summary>
/// <param name="t">Элемент для вставки</param>
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
/// Получает элемент по текущему индексу, затем уменьшает этот индекс на 1
/// </summary>
/// <returns>элемент по текущему индексу</returns>
template<class T>
T TStack<T>::pop()
{
	return items[current_index--];
}
template<class T>
/// <summary>
/// Если текущий индекс < 0 - устанавливает res_marker в false и возвращает NULL
/// <para/> Иначе устанавливает res_marker в true, получает элемент по текущему индексу, затем уменьшает этот индекс на 1
/// </summary>
/// <returns>элемент по текущему индексу</returns>
T TStack<T>::try_pop(bool* res_marker)
{
	*res_marker = (current_index >= 0);
	return (*res_marker) ? pop() : NULL;
}
/// <summary>
/// Получает элемент по текущему индексу, не уменьшая текущий индекс
/// </summary>
/// <returns>элемент по текущему индексу</returns>
template<class T>
T TStack<T>::peek()
{
	return items[current_index];
}
/// <summary>
/// Возвращает количество хранимых элементов, а не вместимость.
/// </summary>
/// <returns>количество элементов в стеке</returns>
template<class T>
int TStack<T>::count()
{
	return current_index + 1;
}