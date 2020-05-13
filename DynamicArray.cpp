/*
			Static Array vs	Dynamic Arry
Access 			 O(1)			O(1)
Search			 O(n)			O(n)
Insertion		 N/A 			O(n)
Appending		 N/A 			O(1)
Deletion		 N/A 			O(n)

An implementaion of a Dynamic Array

*/

#include<iostream>
#include <stdexcept>
using namespace std;

template <class T> class DynamicArray{
	private:
		T * arr = NULL;
		// Length of Array as perceived by User
		int length = 0;
		// Actual length of Array
		int capacity = 0;

	public:
		//Constructor where capacity if 16 by default
		DynamicArray(){
			arr = new T [16];
		}
		DynamicArray(int capacity){
			try{
				if(capacity < 0) 
				    throw invalid_argument("Capacity cannot be negative");
				else{
				    this->capacity = capacity;
				    arr = new T[capacity];
				}
			}catch (exception &exception){
				cerr << "DynamicArray() exception: " << exception.what() << endl;
			}
		}
		~DynamicArray(){
		    if(arr != NULL){
		        delete[] arr;
		    }
		}
		int size(){
			return length;
		}
		bool isEmpty(){
			return (length == 0)? true : false;
		}

		T get(int index){
			try{
				if(index < 0 || index >= length) throw out_of_range("Index is out of range");
				else{
					return arr[index];
				}

			}catch(exception &exception){
				cerr << "get() exception: " << exception.what() << endl;
			}

		}

		void set(int index, T val){
			try{
				if(index < 0 || index >= length) throw out_of_range("Index is out of range");
				else{
					arr[index] = val;
				}

			}catch(exception &exception){
				cerr << "set() exception: " << exception.what() << endl;
			}
		}

		void clear(){
			for(int i = 0; i < capacity; i++){
				arr[i] = NULL;
			}
			length = 0;
		}

		void add(T val){

			if(length >= capacity){
				if(capacity == 0) capacity = 1;
				else capacity *= 2;

				T * nArr = new T[capacity];
				for (int i = 0; i < length; ++i){
					nArr[i] = arr[i];
				}
				T * temp = arr;
				if(temp != NULL)delete[] temp;
				arr = nArr;
			}

			arr[length] = val;
			length++;

		}

		/*
			input: index
			output: typename T the value removed
		*/
		T removeAt(int index){
			try{
				if(index < 0 || index >= length) throw out_of_range("Index is out of range");
				else{
					T ret = arr[index];
					int i, j;
					i = index;
					j = index + 1;
					while(i < length && j < length ){
						arr[i] = arr[j];
						i++;
						j++;
					}
					length--;
					return ret;
				}

			}catch(exception &exception){
				cerr << "removeAt() exception: " << exception.what() << endl;
			}
		}

		/*
			input: T val
			output: bool indicating whether or not removal of val was successful
		*/
		bool remove(T val){
			for(int i = 0; i < length; i++){
				if(arr[i] == val){
					removeAt(i);
					return true;
				}
			}
			return false;
		}
	
		/*
			input:  T val
			output: returns an int indicating the index of val or -1 indicating value not found
		*/
		bool indexOf(T val){
			for(int i = 0; i < length; i++){
				if(arr[i] == val){
					return i;
				}
			}
			return -1;
		}

		bool contains(T val){
			if(indexOf(val) != -1){
				return true;
			}else{
				return false;
			}

		}

		void printArr(){
			for(int i = 0; i < length; i++){
				cout << arr[i] << " ";
			}
			cout << endl;
		}

};


int main(){
	DynamicArray<int> testArr = DynamicArray<int>(-1);
	
	DynamicArray<int>testArr1 = DynamicArray<int>();
	testArr1.add(1);
	testArr1.add(100);
	testArr1.printArr();
	testArr1.remove(1);
	testArr1.printArr();
	testArr1.add(-1);
	cout << testArr1.size();
	
	return 0;

}