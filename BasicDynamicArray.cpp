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
		// Actual length of the Dynamic Array 
		size_t avaliable = 0;
		
		// Length of the Array as Perceived By Users
		size_t length = 0;
		
		// Pointer to the array
		T * arr = nullptr;

	public: 
		// Default Constructor
		DynamicArray(){
			// Initialize avaliable to 16 now
			this -> avaliable = 16;
			arr = new T[16];
		}

		// Pass in an integer
		DynamicArray(int size){
			try{
				if(size <= 0){
					throw invalid_argument("Capacity cannot be negative");
				}else{
					this -> avaliable = size;
					arr = new T[size];
				}
			}catch(exception &exception){
				cerr << "Dynamic Array Error: " << exception.what() << endl;
			}
		}
}

