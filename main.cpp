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

class PriorityIncident {
public:
    int id;
    string type;
    int priority;

    PriorityIncident(int i = 0, string t = "", int p = 1) {
        id = i;
        type = t;
        priority = p;
    }

    bool operator<(const PriorityIncident& other) const {
        return priority < other.priority; 
    }
};

class LinkedListPriorityQueue {
    ListNode<PriorityIncident>* head;

public:
    LinkedListPriorityQueue() {
        head = NULL;
    }


    ~LinkedListPriorityQueue() {
        while (head != NULL) {
            ListNode<PriorityIncident>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push(PriorityIncident incident) {
        ListNode<PriorityIncident>* newNode = new ListNode<PriorityIncident>(incident);
        
        if (head == NULL || incident.priority > head->data.priority) {
            newNode->next = head;
            head = newNode;
        } else {
            ListNode<PriorityIncident>* current = head;
            
            while (current->next != NULL && 
                   current->next->data.priority >= incident.priority) {
                current = current->next;
            }
            
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    PriorityIncident pop() {
        if (head == NULL) {
            return PriorityIncident();
        }
        
        ListNode<PriorityIncident>* temp = head;
        PriorityIncident item = head->data;
        head = head->next;
        delete temp;
        
        return item;
    }

    bool isEmpty() {
        return head == NULL;
    }

    void display() {
        cout << "\n=== PRIORITY QUEUE (Linked List) ===\n";
        cout << "(Highest priority first)\n";
        
        if (head == NULL) {
            cout << "Queue is empty!\n";
            return;
        }
        
        ListNode<PriorityIncident>* current = head;
        int index = 1;
        
        while (current != NULL) {
            cout << index++ << ". ID: " << current->data.id 
                 << " | Type: " << current->data.type 
                 << " | Priority: " << current->data.priority << endl;
            current = current->next;
        }
    }
};

class EmployeeTreeNode {
public:
    string username;
    string role;
    EmployeeTreeNode* parent;
    vector<EmployeeTreeNode*> children;

   EmployeeTreeNode(string uname, string r) {
        username = uname;
        role = r;
        parent = NULL;
    }


    void addChild(EmployeeTreeNode* child) {
        child->parent = this;
        children.push_back(child);
    }

    void display(int level = 0) {
        string indent(level * 4, ' ');
        cout << indent << "|-- " << username << " (" << role << ")" << endl;
        
        for (auto child : children) {
            child->display(level + 1);
        }
    }
};

class OrganizationTree {
    EmployeeTreeNode* root;
    unordered_map<string, EmployeeTreeNode*> nodeMap;

public:
    OrganizationTree() {
        root = NULL;
    }


    ~OrganizationTree() {
        clearTree(root);
    }

    void clearTree(EmployeeTreeNode* node) {
        if (node == NULL) return;
        
        for (auto child : node->children) {
            clearTree(child);
        }
        delete node;
    }

    void buildHierarchy(const vector<pair<string, string>>& employees, 
                       const vector<pair<string, string>>& relationships) {
        for (const auto& emp : employees) {
            EmployeeTreeNode* node = new EmployeeTreeNode(emp.first, emp.second);
            nodeMap[emp.first] = node;
            
            if (emp.second == "admin") {
                root = node;
            }
        }

        for (const auto& rel : relationships) {
            string parent = rel.first;
            string child = rel.second;
            
            if (nodeMap.find(parent) != nodeMap.end() && 
                nodeMap.find(child) != nodeMap.end()) {
                nodeMap[parent]->addChild(nodeMap[child]);
            }
        }
    }

    void displayHierarchy() {
        if (root == NULL) {
            cout << "Organization hierarchy not built yet!\n";
            return;
        }
        
        cout << "\n=== ORGANIZATION HIERARCHY TREE ===\n";
        cout << "Root: " << root->username << " (" << root->role << ")\n";
        cout << "-----------------------------------\n";
        root->display();
    }

    vector<string> getSubordinates(string username) {
        vector<string> subordinates;
        
        if (nodeMap.find(username) == nodeMap.end()) {
            return subordinates;
        }
        
        EmployeeTreeNode* node = nodeMap[username];
        for (auto child : node->children) {
            subordinates.push_back(child->username);
        }
        
        return subordinates;
    }

    string getManager(string username) {
        if (nodeMap.find(username) == nodeMap.end() || 
            nodeMap[username]->parent == NULL) {
            return "";
        }
        
        return nodeMap[username]->parent->username;
    }

    vector<string> getEscalationPath(string username) {
        vector<string> path;
        
        if (nodeMap.find(username) == nodeMap.end()) {
            return path;
        }
        
        EmployeeTreeNode* current = nodeMap[username];
        while (current != NULL) {
            path.push_back(current->username);
            current = current->parent;
        }
        
        reverse(path.begin(), path.end());
        return path;
    }
};

class CollaborationGraph {
    unordered_map<string, vector<pair<string, int>>> adjList; 
    unordered_map<string, string> employeeTeam; 

public:
    void addEmployee(string username, string team) {
        employeeTeam[username] = team;
    }

    void addCollaboration(string emp1, string emp2, int weight = 1) {
        adjList[emp1].push_back({emp2, weight});
        adjList[emp2].push_back({emp1, weight});
    }

    vector<string> findExperts(string incidentType) {
        vector<string> experts;
        
        unordered_map<string, int> collaborationScore;
        
        for (const auto& entry : adjList) {
            string employee = entry.first;
            collaborationScore[employee] = entry.second.size();
        }
        
        vector<pair<string, int>> sortedExperts(
            collaborationScore.begin(), collaborationScore.end());
        
        sort(sortedExperts.begin(), sortedExperts.end(),
             [](const pair<string, int>& a, const pair<string, int>& b) {
                 return a.second > b.second;
             });
        
        for (int i = 0; i < min(5, (int)sortedExperts.size()); i++) {
            experts.push_back(sortedExperts[i].first);
        }
        
        return experts;
    }

    vector<string> findTeamCollaborators(string teamName) {
        vector<string> collaborators;
        unordered_set<string> visited;
        
        for (const auto& entry : employeeTeam) {
            if (entry.second == teamName) {
                string employee = entry.first;
                
                if (adjList.find(employee) != adjList.end()) {
                    for (const auto& colleague : adjList[employee]) {
                        string collabName = colleague.first;
                        
                        if (employeeTeam[collabName] != teamName && 
                            visited.find(collabName) == visited.end()) {
                            collaborators.push_back(collabName);
                            visited.insert(collabName);
                        }
                    }
                }
            }
        }
        
        return collaborators;
    }

    void displayGraph() {
        cout << "\n=== TEAM COLLABORATION GRAPH ===\n";
        
        for (const auto& entry : adjList) {
            string employee = entry.first;
            cout << employee << " (" << employeeTeam[employee] << ") -> ";
            
            for (const auto& colleague : entry.second) {
                cout << colleague.first << "(" << colleague.second << ") ";
            }
            cout << endl;
        }
    }

    vector<string> findShortestPath(string start, string end) {
        if (adjList.find(start) == adjList.end() || 
            adjList.find(end) == adjList.end()) {
            return {};
        }

        unordered_map<string, string> parent;
        unordered_set<string> visited;
        queue<string> q;

        q.push(start);
        visited.insert(start);
        parent[start] = "";

        while (!q.empty()) {
            string current = q.front();
            q.pop();

            if (current == end) {
                vector<string> path;
                string node = end;
                
                while (node != "") {
                    path.push_back(node);
                    node = parent[node];
                }
                
                reverse(path.begin(), path.end());
                return path;
            }

            for (const auto& neighbor : adjList[current]) {
                string next = neighbor.first;
                
                if (visited.find(next) == visited.end()) {
                    visited.insert(next);
                    parent[next] = current;
                    q.push(next);
                }
            }
        }

        return {}; 
    }
};

string toLower(string str) {
    for (char& c : str) {
        c = tolower(c);
    }
    return str;
}

string getCurrentTime() {
    time_t now = time(0);
    string dt = ctime(&now);
    dt.pop_back();
    return dt;
}