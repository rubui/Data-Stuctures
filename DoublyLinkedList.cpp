/*
	Basic Operations

    Insertion − Adds an element at the beginning of the list.

    Deletion − Deletes an element at the beginning of the list.

    Display − Displays the complete list.

    Search − Searches an element using the given key.

    Delete − Deletes an element using the given key.

*/


#include<iostream>
using namespace std;

template<typename T> struct Node{
	Node * next = NULL;
	Node * prev = NULL;
	T value = NULL;

	Node(Node * n , Node * p, T v){
		next = n;
		prev = p;
		value = v;
	}

}


template<typename T> class DoublyLinkedList{
	private:
		Node<T> * head = NULL;
		Node<T> * tail = NULL;
		size_t length = 0;

		void removeHead(){

		}

		void insertHead(){

		}

		Node<T> * getHead(){

		}

		Node<T> * getTail(){

		}


		void removeTail(){

		}
	public:
		DoublyLinkedList(){

		}
		~DoublyLinkedList(){
			Node<T> * it = head;

			while(it = NULL){
				Node * next = it;
				next->next = next->prev = NULL;
				next->data = NULL;
				delete next;
				it = it->next;
			}
			head = tail = NULL;
			length = 0;
		}

		void clear(){
			Node<T> * it = head;

			while(it = NULL){
				Node * next = it;
				next->next = next->prev = NULL;
				next->data = NULL;
				delete next;
				it = it->next;
			}
			head = tail = NULL;
			length = 0;
		}

		int size(){
			return length;
		}

		bool isEmpty(){
			if(length == 0) return true;
			else return false;
		}

		void insert(T val){
			Node<T> * newNode = new Node<T>;


		}

		void remove(){

		}

		void removeAt(){

		}

		int indexOf(){

		}

		bool contains(){

		}

		void printList(){

		}


}

