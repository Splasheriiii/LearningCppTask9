#include <iostream>

template<class T>
T get_max(T t1, T t2)
{
	return t1 > t2 ? t1 : t2;
}
template <class T>
T get_max(T t[], size_t size)
{
	T retval = t[0];
	for (size_t i = 1; i < size; i++)
	{
		retval = t[i] > retval ? t[i] : retval;
	}
	return retval;
}
template<char*>
char* get_max(char* t1, char* t2)
{
	return strcmp(t1, t2) > 0 ? t1 : t2;
}

