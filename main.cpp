#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cctype>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
using namespace std;
template<typename T>
class ListNode{
public:
    T data;
    ListNode* next;
    
    ListNode(T value) {
        data = value;      
        next = NULL;  
    }
};

<<<<<<< HEAD
=======
template<typename T>
class LinkedListStack{
    ListNode<T>* top;
    int size;

public:
    LinkedListStack(){
        top = NULL;
        size = 0;
    }


    ~LinkedListStack(){
        while (!isEmpty()){
            pop();
        }
    }

    void push(T item){
        ListNode<T>* newNode = new ListNode<T>(item);
        newNode->next = top;
        top = newNode;
        size++;
    }

    T pop(){
        if (isEmpty()) {
            return T();
        }
        
        ListNode<T>* temp = top;
        T item = top->data;
        top = top->next;
        delete temp;
        size--;
        
        return item;
    }

    bool isEmpty() {
        return top == NULL;
    }

    T peek() {
        if (isEmpty()) {
            return T();
        }
        return top->data;
    }

    int getSize() {
        return size;
    }
};
>>>>>>> 05348abf93485248b419517039ec9de757f3d075
