#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
using namespace std;

class EmptyHeap: public exception
{
  virtual const char* what() const throw()
  {
    return "Heap is Empty";
  }
} myex;

//Min heap by default
class  Heap{
	private:
		vector<int> heap;

		//DO NOT USE ON ROOT
		int getParent(size_t i){
				return (i - 1)/2;
		}

		int getLeft(size_t i){
			return (2*i + 1);
		}

		int getRight(size_t i){
			return (2*i + 2);
		}

		//Provide the 2 indicies
		void swap(size_t i, size_t j){
			int temp = heap[i];
			heap[i] = heap[j];
			heap[j] = temp;
		}


		void heapDown(size_t i){

			size_t left = getLeft(i);
			int right = getRight(i);

			int smallest = i;

			if (left < heap.size() && heap[left] < heap[i])
				smallest = left;

			if (right < heap.size() && heap[right] < heap[smallest])
				smallest = right;

			if (smallest != i) {
				swap(i, smallest);
				heapDown(smallest);
			}
			
		}



	public:
		Heap(){

		}
		
		size_t size(){
		    return heap.size();
		}


		void push(int i){
			heap.push_back(i);
			size_t currPos = heap.size() - 1;
			size_t parPos = getParent(currPos);
			while(currPos != 0 && heap[parPos] > heap[currPos]){
				swap(parPos, currPos);
				currPos = parPos;
				parPos = getParent(currPos);
			}

		}

		int top(){
		    try{
			    if(heap.size() != 0){
				    return heap[0];
			    }else{
			        throw myex;
			    }
		        
		    }catch(exception &e){
                cout << e.what() << '\n';
		    }
		}

		int getMin(){
		    try{
			    if(heap.size() == 0){
			        throw myex;
			    }
			    int ret;
			    ret = heap[0];
			    
			    int pushVal = heap.back();
			    heap.pop_back();
			    if(heap.size() != 0){
			        heap[0] = pushVal;
			    }
			    heapDown(0);
			    return ret;
		        
		    }catch(exception &e){
                cout << e.what() << '\n';
		    }
		}




};