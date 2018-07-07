// LinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LinkedList.h"
#include<iostream>
using namespace std;

int main()
{
	LinkedList<size_t> linked_list;
	for (size_t i = 0; i < SIZE; ++i)
	{
		linked_list.push_back_node(1+i);
	}
	/*
	cout << "iterative length =" << linked_list.get_length(ITERATOR_FLAG) << endl;
	cout << "recursive length =" << linked_list.get_length(RECURSIVE_FLAG) << endl;
	linked_list.print();
	*/
	//linked_list.delete_node_by_value(10);
	
	//linked_list.delete_node_by_position(5);
	//linked_list.delete_node_by_position(SIZE-2);
	/*
	cout << "iterative length =" << linked_list.get_length(ITERATOR_FLAG) << endl;
	cout << "recursive length =" << linked_list.get_length(RECURSIVE_FLAG) << endl;
	linked_list.print();
	*/
	//linked_list.delete_list_by_recursive();
	//linked_list.delete_list_by_iterator();
	linked_list.print();
	/*
	cout << "5 exist :" << linked_list.find_element(5, ITERATOR_FLAG) << endl;
	cout << "5 exist :" << linked_list.find_element(5, RECURSIVE_FLAG) << endl;
	cout << "15 exist :" << linked_list.find_element(15, ITERATOR_FLAG) << endl;
	cout << "15 exist :" << linked_list.find_element(15, RECURSIVE_FLAG) << endl;
	*/
	Node<size_t>*sizeth_node = linked_list.get_nth_node(SIZE - 1, ITERATOR_FLAG);
	cout << SIZE - 1 << "th node: data =" << sizeth_node->data << endl;
	Node<size_t>*fifth_node = linked_list.get_nth_node(5, RECURSIVE_FLAG);
	cout << 5<< "th node: data =" << fifth_node->data << endl;
	Node<size_t>*nth_node_from_the_end = linked_list.get_nth_node_from_end(3, ITERATOR_FLAG);
	cout << 3 << "th node: data =" << nth_node_from_the_end->data << endl;
    return 1;
}





template<typename T>
LinkedList<T>::LinkedList()
{
	head = nullptr;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
	
}

template<typename T>
void LinkedList<T>::print()
{
	recusive_print(head);
	cout << endl;
}

template<typename T>
void LinkedList<T>::recusive_print(Node<T> * head)
{
	if (head)
	{
		cout << head->data << " ";
		recusive_print(head->next);
		
	}
}


/*
*
*
*/

template<typename T>
void LinkedList<T>::recursive_delete_node_by_value(Node<T>* &head, T value)
{
	if (head)
	{
		if (head->data == value)
		{
			Node<T>* tmp = head;
			head = head->next;
			delete tmp;
		}
		else
		{
			recursive_delete_node(head->next, value);
		}
	}
}

template<typename T>
void LinkedList<T>::recursive_delete_node_by_position(Node<T>*& head, size_t& pos)
{
	if (head)
	{
		if (pos == 0)
		{
			Node<T>* delete_node = head;
			head = head->next;
			delete delete_node;
		}
		else if (pos > 0)
		{
			recursive_delete_node_by_position(head->next, --pos);
		}
	}
}

template<typename T>
void LinkedList<T>::delete_node_by_value(T value)
{
	recursive_delete_node_by_value(head, value);
}

template<typename T>
void LinkedList<T>::delete_node_by_position(size_t pos)
{
	recursive_delete_node_by_position(head, pos);
}

template<typename T>
void LinkedList<T>::delete_list_by_iterator()
{
	for (Node<T>*iter_node = head; iter_node!= nullptr; iter_node = head)
	{
		head = head->next;
		delete iter_node;
	}
}


template<typename T>
void LinkedList<T>::recursive_delete_list(Node<T>*& head)
{
	if (head)
	{
		Node<T>*delete_node = head;
		head = head->next;
		delete delete_node;
		recursive_delete_list(head);
	}
}

template<typename T>
void LinkedList<T>::delete_list_by_recursive()
{
	recursive_delete_list(head);
}


/*
*
*
*/

template<typename T>
void LinkedList<T>::recursive_push_back_node(Node<T> *& head, T value)
{
	if (!head)
	{
		Node<T> *newnode = new Node<T>();
		newnode->data = value;
		newnode->next = nullptr;
		head = newnode;
	}
	else
	{
		recursive_push_back_node(head->next, value);
	}
}

template<typename T>
void LinkedList<T>::push_back_node(T value)
{
	recursive_push_back_node(head, value);
}


template<typename T>
void LinkedList<T>::get_length_by_recurse(Node<T>* head, size_t& count)
{
	if (head)
	{
		get_length_by_recurse(head->next, ++count);
	}
}

template<typename T>
size_t LinkedList<T>::get_length_by_iteration()
{
	size_t count = 0;
	for (Node<T>*iter = head; iter != nullptr; iter=iter->next, ++count)
	{
		
	}
	return count;
}



template<typename T>
size_t LinkedList<T>::get_length(size_t flag)
{
	switch (flag)
	{
	case ITERATOR_FLAG:
		return get_length_by_iteration();
	case RECURSIVE_FLAG:
	{
		size_t count = 0;
		get_length_by_recurse(head, count);
		return count;
	}
		
	default:
		break;
	}
}


template<typename T>
bool LinkedList<T>::search_value_by_iterator(T value)
{
	bool found = false;
	for (Node<T>*iter = head; iter != nullptr; iter = iter->next)
	{
		if (iter->data == value)
		{
			found = true;
		}
	}
	return found;
}

template<typename T>
bool LinkedList<T>::search_value_by_recurse(Node<T>* head, T value)
{
	if (head)
	{
		if (head->data == value)
		{
			return true;
		}
		else {
			return search_value_by_recurse(head->next, value);
		}
	}
	return false;
}



template<typename T>
bool LinkedList<T>::find_element(T value, size_t mode)
{
	bool found = false;
	switch (mode)
	{
	case ITERATOR_FLAG:
		found = search_value_by_iterator(value);
		break;
	case RECURSIVE_FLAG:
		found = search_value_by_recurse(head, value);
		break;
	default:
		break;
	}
	return found;
}



template<typename T>
Node<T>* LinkedList<T>::get_nth_node_by_iterator(size_t index)
{
	Node<T>*iter = head;
	for (; iter != nullptr && index != 0; iter = iter->next, --index)
	{

	}
	return iter;
}

template<typename T>
Node<T>* LinkedList<T>::get_nth_node_by_recurse(Node<T>* head, size_t index)
{
	if (head)
	{
		if (index != 0 )
		{
			return get_nth_node_by_recurse(head->next, --index);
		}
		else
		{
			return head;
		}
	}
	return nullptr;
}

template<typename T>
Node<T>* LinkedList<T>::get_nth_node(size_t index, size_t mode)
{
	Node<T>* node = nullptr;
	switch (mode)
	{
	case ITERATOR_FLAG:
		node = get_nth_node_by_iterator(index);
		break;
	case RECURSIVE_FLAG:
		node = get_nth_node_by_recurse(head, index);
		break;
	default:
		break;
	}
	return node;
}

template<typename T>
Node<T>* LinkedList<T>::get_nth_node_from_end_by_iterator(size_t index)
{
	Node<T>* nthNode = head;
	Node<T>* tailNode = head;
	size_t i = 0;
	for (; i < index;  ++i)
	{
		if (tailNode->next)tailNode = tailNode->next;
		else break;
	}
	if (i != index)
	{
		nthNode = nullptr;
	}
	else
	{
		for (; tailNode->next != nullptr;)
		{
			tailNode = tailNode->next;
			nthNode = nthNode->next;
		}
	}
	return nthNode;
}

template<typename T>
Node<T>* LinkedList<T>::get_nth_node_from_end_by_recurse(Node<T>*head, size_t index)
{

	return nullptr;
}


/*
* this version is used without length of list
*/
template<typename T>
Node<T>* LinkedList<T>::get_nth_node_from_end(size_t index, size_t mode)
{
	Node<T>* node = nullptr;

	switch (mode)
	{
	case ITERATOR_FLAG:
		node = get_nth_node_from_end_by_iterator(index);
		break;
	case RECURSIVE_FLAG:
		node = get_nth_node_from_end_by_recurse(head, index);
		break;
	default:
		break;
	}
	return node;
}

template<typename T>
Node<T>* LinkedList<T>::get_middle_node_by_iterator(size_t index)
{
	Node<T>* fast_node = head;
	Node<T>* slow_node = head;
	for (; ; )
	{

	}
	return nullptr;
}


template<typename T>
void LinkedList<T>::print_middle(size_t mode)
{
	Node<T>* node = nullptr;
	switch (mode)
	{
	case ITERATOR_FLAG:
		node = get_middle_node_by_iterator(index);
		break;
	case RECURSIVE_FLAG:
		node = get_middle_node_by_recurse(head, index);
		break;
	default:
		break;
	}
	
}
