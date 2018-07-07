#pragma once
#include<string>
using namespace std;
const size_t SIZE = 10;
const size_t ITERATOR_FLAG = 0;
const size_t RECURSIVE_FLAG = 1;

#define next(n) get_string_next_n_times(n)

#define get_string_next_n_times(n) \


template<typename T> struct  Node
{
	T data;
	Node* next;
};

template<typename T>
class LinkedList
{
private:
	Node<T>* head;
	void recursive_push_back_node(Node<T>*&head, T value);
	void recusive_print(Node<T>* head);
	void recursive_delete_node_by_value(Node<T>* &head, T value);
	void recursive_delete_node_by_position(Node<T>* &head, size_t& pos);
	void recursive_delete_list(Node<T>*&head);

	void get_length_by_recurse(Node<T>*head, size_t& count);
	size_t get_length_by_iteration();
	bool search_value_by_iterator(T value);
	bool search_value_by_recurse(Node<T>* head, T value);
	Node<T>* get_nth_node_by_iterator(size_t index);
	Node<T>* get_nth_node_by_recurse(Node<T>* head, size_t index);

	Node<T>* get_nth_node_from_end_by_iterator(size_t index);
	Node<T>* get_nth_node_from_end_by_recurse(Node<T>*head,size_t index);

	Node<T>*get_middle_node_by_iterator(size_t index);
public:
	LinkedList();
	~LinkedList();
	void print();
	
	//void insert_node(T value);
	//void recursive_insert_node(Node* head, T value);
	/*
	* 3) Linked List Insertion
	*/
	void push_back_node(T value);

	/*
	* 4) Linked List Deletion (Deleting a given key)
	*/
	void delete_node_by_value(T value);

	/*
	* 5) Linked List Deletion (Deleting a key at given position)
	*/
	void delete_node_by_position(size_t pos);

	/*
	* 6) Write a function to delete a Linked List
	*/
	void delete_list_by_iterator();
	void delete_list_by_recursive();

	/*
	* 7) Find Length of a Linked List (Iterative and Recursive)
	*/
	size_t get_length(size_t flag);

	/*
	* 8) Search an element in a Linked List (Iterative and Recursive)
	*/
	bool find_element(T value, size_t mode);

	/*
	* 9) Write a function to get Nth node in a Linked List
	*/
	Node<T>* get_nth_node(size_t index, size_t mode);

	/*
	* 10) Nth node from the end of a Linked List
	*/
	Node<T>* get_nth_node_from_end(size_t index, size_t mode);
	
	/*
	* 11) Print the middle of a given linked list
	*/
	void print_middle(size_t mode);
};

