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

template<typename T>
class LinkedListQueue {
    ListNode<T>* front;
    ListNode<T>* rear;
    int size;

public:
   LinkedListQueue(){
        front = NULL;
        rear = NULL;
        size = 0;
    }


    ~LinkedListQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(T item) {
        ListNode<T>* newNode = new ListNode<T>(item);
        
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    T dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return T();
        }
        
        ListNode<T>* temp = front;
        T item = front->data;
        front = front->next;
        
        if (front == NULL) {
            rear = NULL;
        }
        
        delete temp;
        size--;
        return item;
    }

    bool isEmpty() {
        return front == NULL;
    }

    T peek() {
        if (isEmpty()) {
            return T();
        }
        return front->data;
    }

    int getSize() {
        return size;
    }};
    
template<typename T>
class LinkedListQueue {
    ListNode<T>* front;
    ListNode<T>* rear;
    int size;

public:
   LinkedListQueue(){
        front = NULL;
        rear = NULL;
        size = 0;
    }


    ~LinkedListQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(T item) {
        ListNode<T>* newNode = new ListNode<T>(item);
        
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    T dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return T();
        }
        
        ListNode<T>* temp = front;
        T item = front->data;
        front = front->next;
        
        if (front == NULL) {
            rear = NULL;
        }
        
        delete temp;
        size--;
        return item;
    }

    bool isEmpty() {
        return front == NULL;
    }

    T peek() {
        if (isEmpty()) {
            return T();
        }
        return front->data;
    }

    int getSize() {
        return size;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        
        cout << "Queue contents (size=" << size << "):\n";
        ListNode<T>* current = front;
        int index = 0;
        
        while (current != NULL) {
            cout << "Node " << index++ << ": " << current->data << endl;
            current = current->next;
        }
    }
};
template<typename T>
class LinkedListCircularQueue {
    ListNode<T>* rear; 
    int size;
    int capacity;

public:
    LinkedListCircularQueue(int cap = 100) {
        rear = NULL;
        size = 0;
        capacity = cap;
    }


    ~LinkedListCircularQueue() {
        if (isEmpty()) return;
        
       
        if (rear->next == rear) {
            delete rear;
        } else {
            ListNode<T>* current = rear->next;
            ListNode<T>* start = current;
            
            do {
                ListNode<T>* temp = current;
                current = current->next;
                delete temp;
            } while (current != start);
        }
    }

    void enqueue(T item) {
        if (isFull()) {
            cout << "Queue is full!\n";
            return;
        }
        
        ListNode<T>* newNode = new ListNode<T>(item);
        
        if (isEmpty()) {
            rear = newNode;
            rear->next = rear;
        } else {
            newNode->next = rear->next; 
            rear->next = newNode; 
            rear = newNode; 
        }
        size++;
    }

    T dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return T();
        }
        
        ListNode<T>* frontNode;
        T item;
        
        if (rear->next == rear) { 
            frontNode = rear;
            item = frontNode->data;
            delete frontNode;
            rear = nullptr;
        } else {
            frontNode = rear->next; 
            item = frontNode->data;
            rear->next = frontNode->next; 
            delete frontNode;
        }
        
        size--;
        return item;
    }

    bool isEmpty() {
        return rear == NULL;
    }

    bool isFull() {
        return size >= capacity;
    }

    T peek() {
        if (isEmpty()) {
            return T();
        }
        return rear->next->data; 
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        
        cout << "Circular Queue contents (size=" << size << ", capacity=" << capacity << "):\n";
        ListNode<T>* current = rear->next; 
        ListNode<T>* start = current;
        int index = 0;
        
        do {
            cout << "Node " << index++ << ": " << current->data << endl;
            current = current->next;
        } while (current != start);
    }
};

  
