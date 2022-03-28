#pragma once
template<class T>
class TStack 
{
public:
	TStack();
	~TStack();
	void push(T t);
	T pop();
	T try_pop(bool*);
	T peek();
	int count();
private:
	int current_index;
	T* items;
	int size;
};