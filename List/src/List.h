//List template for single-linked list
//T is a placeholder for the data type of a list item
//Incomplete! (only functions necessary for the example are implemented).
#pragma once
#include <iterator>

template<typename T>
class List
{
public:
	//CopyConstructor, Destructor and AssignmentOperator are missing!!

	//push_front() creates a new List element and adds is to the start of the list:
	void push_front(const T& value)
	{
		start = new ListElement(value, start);
	}

private:
	struct ListElement
	{
		T data;
		ListElement* next;
		ListElement(const T& value, ListElement* p)
			: data{value}, next{p}
		{}
	};
	ListElement* start{ nullptr };

public:
	class Iterator
	{
	public:
		//Interfaces required by find():
		using iterator_category = std::forward_iterator_tag;
		using value_type = T;
		using pointer = T*;
		using reference = T&;
		using difference_type = std::ptrdiff_t;

		Iterator(ListElement* init = nullptr)
			: m_currentElement{init}
		{}

		T& operator*() //Dereferencing
		{
			return m_currentElement->data;
		}

		const T& operator*() const //Dereferencing
		{
			return m_currentElement->data;
		}

		Iterator& operator++() //Prefix
		{
			if (m_currentElement) //End not yet reached?
				m_currentElement = m_currentElement->next;

			return *this;
		}

		Iterator operator++(int) //Postfix
		{
			Iterator temp{ *this };
			++*this;

			return temp;
		}

		bool operator==(const Iterator& x) const
		{
			return m_currentElement == x.m_currentElement;
		}

		bool operator!=(const Iterator& x) const
		{
			return m_currentElement != x.m_currentElement;
		}

	private:
		ListElement* m_currentElement; //Reference to current element
	};

	//Some methods of class List use the class iterator(see below):
	Iterator begin() const { return Iterator(start); }
	Iterator end() const { return Iterator(); }
};
