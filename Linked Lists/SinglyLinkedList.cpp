#include <iostream>
#include <stack>

using namespace std;

struct Node{
    int data;
    struct Node * next;
};

class SinglyLinkedList{

    private:
        Node * head;
    public:
        SinglyLinkedList(){
            head = nullptr;
        }
        ~SinglyLinkedList(){
            if(getLength() != 0){
                Node * ptr = head;
                while(ptr!= nullptr){
                    Node * deleteNode = ptr;
                    ptr = ptr->next;
                    delete deleteNode;
                }
            }
            head = nullptr;
        }
        void insert(int data){
            Node * currNode = head;
            Node * newNode = new Node;
            newNode->data = data;
            newNode->next = nullptr;
            if(head == nullptr){
                head = newNode;
            }else{
                while(currNode->next != nullptr){
                    currNode = currNode->next;
                }
                currNode->next = newNode;
            }
        }
        void printList(){
            Node * currNode = head;
            while(currNode != nullptr){
                cout << currNode->data << " -> " ; 
                currNode = currNode->next;
            }
            cout << "NULL" <<  endl;
        }
        void insertAtHead(int num){
            Node * newNode = new Node;
            newNode -> data = num;
            newNode -> next = head;
            head = newNode;
        }
        Node * setHead(Node * node){
            head = node;     
        }
        Node * returnHead(){
            return head;
        }
        Node * returnTail(){
            Node * start = head;
            while(start->next != nullptr){
                start = start->next;
            }
            return start;
        }
        int getLength(){
            int count = 0;
            Node * headIt = head;
            while(headIt != nullptr){
                count++;
                headIt = headIt->next;
            }
            return count;
        }
};