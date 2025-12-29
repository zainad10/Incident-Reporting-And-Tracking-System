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
class Employee {
public:
    string username;
    string password;
    string cnic;
    string role;
    string team;
    string department;

    Employee() {}

    Employee(string u, string p, string c, string r, string t, string d) {
        username = u;
        password = p;
        cnic = c;
        role = r;
        team = t;
        department = d;
    }

    void display() {
        cout << "|-- Username: " << username << "\n";
        cout << "|-- CNIC: " << cnic << "\n";
        cout << "|-- Role: " << role << "\n";
        cout << "|-- Team: " << team << "\n";
        cout << "|-- Department: " << department << "\n";
        cout << "___________________________________________________________________\n";
    }

    string toFileString() {
        return username + "|" + password + "|" + cnic + "|" + role + "|" + team + "|" + department;
    }

    static Employee fromFileString(string line) {
        Employee emp;
        int pos = 0;
        
        pos = line.find("|");
        emp.username = line.substr(0, pos);
        line.erase(0, pos + 1);
        
        pos = line.find("|");
        emp.password = line.substr(0, pos);
        line.erase(0, pos + 1);
        
        pos = line.find("|");
        emp.cnic = line.substr(0, pos);
        line.erase(0, pos + 1);
        
        pos = line.find("|");
        emp.role = line.substr(0, pos);
        line.erase(0, pos + 1);
        
        pos = line.find("|");
        emp.team = line.substr(0, pos);
        line.erase(0, pos + 1);
        
        emp.department = line;
        
        return emp;
    }
};
class Incident {
public:
    int id;
    string reportName;
    string reporterCNIC;
    string location;
    string type;
    string assignedTeam;
    string status;
    string reporterRole;
    string reportTime;
    
    static int nextId;

    Incident() {
        id = nextId++;
        status = "Pending";
        reportTime = getCurrentTime();
    }

    Incident(string name, string cnic, string loc, string t, string team) {
        id = nextId++;
        reportName = name;
        reporterCNIC = cnic;
        location = loc;
        type = t;
        assignedTeam = team;
        status = "Pending";
        reporterRole = "Normal User";
        reportTime = getCurrentTime();
    }

    void displayForm() {
        cout << "\n" << string(40, '=') << "\n";
        cout << "      INCIDENT REPORT FORM\n";
        cout << string(40, '=') << "\n";
        cout << "|-- Incident ID: " << id << "\n";
        cout << "|-- Reporter Name: " << reportName << "\n";
        cout << "|-- Reporter CNIC: " << reporterCNIC << "\n";
        cout << "|-- Reporter Role: " << reporterRole << "\n";
        cout << "|-- Location: " << location << "\n";
        cout << "|-- Incident Type: " << type << "\n";
        cout << "|-- Assigned Team: " << assignedTeam << "\n";
        cout << "|-- Status: " << status << "\n";
        cout << "|-- Reporting Time: " << reportTime << "\n";
        cout << string(40, '=') << "\n";
    }

    string toFileString() {
        return to_string(id) + "|" + reportName + "|" + reporterCNIC + "|" + 
               location + "|" + type + "|" + assignedTeam + "|" + status + "|" + 
               reporterRole + "|" + reportTime;
    }

    static Incident fromFileString(string line) {
        Incident inc;
        int pos = 0;
        
        pos = line.find("|");
        inc.id = stoi(line.substr(0, pos));
        line.erase(0, pos + 1);
        
        pos = line.find("|");
        inc.reportName = line.substr(0, pos);
        line.erase(0, pos + 1);
        
        pos = line.find("|");
        inc.reporterCNIC = line.substr(0, pos);
        line.erase(0, pos + 1);
        
        pos = line.find("|");
        inc.location = line.substr(0, pos);
        line.erase(0, pos + 1);
        
        pos = line.find("|");
        inc.type = line.substr(0, pos);
        line.erase(0, pos + 1);
        
        pos = line.find("|");
        inc.assignedTeam = line.substr(0, pos);
        line.erase(0, pos + 1);
        
        pos = line.find("|");
        inc.status = line.substr(0, pos);
        line.erase(0, pos + 1);
        
        pos = line.find("|");
        inc.reporterRole = line.substr(0, pos);
        line.erase(0, pos + 1);
        
        inc.reportTime = line;
        
        return inc;
    }
};
class Team {
public:
    string name;
    string department;
    string head;
    vector<string> members;
    int totalCases;
    int solvedCases;

    Team() {
        totalCases = 0;
        solvedCases = 0;
    }

    Team(string n, string dept, string h) {
        name = n;
        department = dept;
        head = h;
        totalCases = 0;
        solvedCases = 0;
    }

    void display() {
        cout << "\n" << string(40, '=') << "\n";
        cout << "        TEAM DETAILS\n";
        cout << string(40, '=') << "\n";
        cout << "|-- Team Name: " << name << "\n";
        cout << "|-- Department: " << department << "\n";
        cout << "|-- Team Head: " << head << "\n";
        cout << "|-- Total Cases Assigned: " << totalCases << "\n";
        cout << "|-- Solved Cases: " << solvedCases << "\n";
        if (totalCases > 0) {
            float successRate = (float)solvedCases * 100 / totalCases;
            cout << "|-- Success Rate: " << successRate << "%\n";
        } else {
            cout << "|-- Success Rate: 0%\n";
        }
        
        cout << "|-- Team Members (" << members.size() << "):\n";
        if (members.empty()) {
            cout << "   No members in this team yet.\n";
        } else {
            for (int i = 0; i < members.size(); i++) {
                cout << "   " << i+1 << ". " << members[i] << "\n";
            }
        }
        cout << string(40, '=') << "\n";
    }

    string toFileString() {
        string result = name + "|" + department + "|" + head + "|" + 
                       to_string(totalCases) + "|" + to_string(solvedCases) + "|";
        for (string member : members) {
            result += member + ",";
        }
        return result;
    }

    static Team fromFileString(string line) {
        Team team;
        int pos = 0;
        
        pos = line.find("|");
        team.name = line.substr(0, pos);
        line.erase(0, pos + 1);
        
        pos = line.find("|");
        team.department = line.substr(0, pos);
        line.erase(0, pos + 1);
        
        pos = line.find("|");
        team.head = line.substr(0, pos);
        line.erase(0, pos + 1);
        
        pos = line.find("|");
        team.totalCases = stoi(line.substr(0, pos));
        line.erase(0, pos + 1);
        
        pos = line.find("|");
        team.solvedCases = stoi(line.substr(0, pos));
        line.erase(0, pos + 1);
        
        while (!line.empty()) {
            pos = line.find(",");
            if (pos != string::npos) {
                string member = line.substr(0, pos);
                if (!member.empty()) {
                    team.members.push_back(member);
                }
                line.erase(0, pos + 1);
            } else {
                if (!line.empty()) {
                    team.members.push_back(line);
                }
                break;
            }
        }
        
        return team;
    }
};
class IncidentSystem {
private:
    vector<Employee> employees;
    vector<Team> teams;
    vector<Incident> incidents;
    
    map<string, Employee> employeeMap; 
    map<string, int> incidentTypeCount;
    
    LinkedListQueue<Incident> incidentQueue;
    LinkedListStack<string> activityLog;
    LinkedListPriorityQueue priorityQueue;
    OrganizationTree orgTree;
    CollaborationGraph collabGraph;
    const string EMP_FILE = "employees.dat";
    const string TEAM_FILE = "teams.dat";
    const string INC_FILE = "incidents.dat";

public:
    IncidentSystem() {
        loadData();
        if (employees.empty()) {
            createDefaultData();
        }
        buildDataStructures();
    }

    ~IncidentSystem() {
        saveData();
    }

    void buildDataStructures() {
        vector<pair<string, string>> empList;
        vector<pair<string, string>> relationships;
        
        for (const Employee& emp : employees) {
            empList.push_back({emp.username, emp.role});
            collabGraph.addEmployee(emp.username, emp.team);
        }
        relationships.push_back({"admin", "ali"});
        relationships.push_back({"ali", "sarah"}); 
        relationships.push_back({"ali", "john"}); 
        relationships.push_back({"sarah", "fatima"}); 
        relationships.push_back({"john", "mike"}); 
        relationships.push_back({"john", "ahmed"}); 
        
        orgTree.buildHierarchy(empList, relationships);
        for (const Incident& inc : incidents) {
            string assignedTeam = inc.assignedTeam;
            for (const Team& team : teams) {
                if (team.name == assignedTeam) {
                    for (int i = 0; i < team.members.size(); i++) {
                        for (int j = i + 1; j < team.members.size(); j++) {
                            collabGraph.addCollaboration(team.members[i], team.members[j]);
                        }
                    }
                    break;
                }
            }
        }
    }

    void createDefaultData() {
        Team itTeam("IT Support", "IT", "admin");
        Team hrTeam("HR Team", "HR", "admin");
        Team opsTeam("Operations", "Operations", "admin");
        
        teams.push_back(itTeam);
        teams.push_back(hrTeam);
        teams.push_back(opsTeam);
        
        Employee admin("admin", "admin123", "35201-1234567-0", "admin", "IT Support", "IT");
        Employee emp1("rozeen", "rozeen123", "35201-1234567-1", "team_member", "IT Support", "IT");
        Employee emp2("rameen", "rameen123", "35201-1234567-2", "team_head", "HR Team", "HR");
        Employee emp3("ali", "ali123", "35201-1234567-3", "dept_head", "Operations", "Operations");
        Employee emp4("zaina", "zaina123", "35201-1234567-4", "team_member", "IT Support", "IT");
        Employee emp5("eman", "eman123", "35201-1234567-5", "team_member", "HR Team", "HR");
        Employee emp6("ahmed", "ahmed123", "35201-1234567-6", "team_member", "Operations", "Operations");
        
        employees.push_back(admin);
        employees.push_back(emp1);
        employees.push_back(emp2);
        employees.push_back(emp3);
        employees.push_back(emp4);
        employees.push_back(emp5);
        employees.push_back(emp6);
        
        employeeMap["admin"] = admin;
        employeeMap["rozeen"] = emp1;
        employeeMap["rameen"] = emp2;
        employeeMap["ali"] = emp3;
        employeeMap["zaina"] = emp4;
        employeeMap["eman"] = emp5;
        employeeMap["ahmed"] = emp6;
        for (Team& team : teams) {
            if (team.name == "IT Support") {
                team.members.push_back("admin");
                team.members.push_back("rozeen");
                team.members.push_back("zaina");
            }
            else if (team.name == "HR Team") {
                team.members.push_back("rameen");
                team.members.push_back("eman");
            }
            else if (team.name == "Operations") {
                team.members.push_back("ali");
                team.members.push_back("ahmed");
            }
        }
        Incident inc1("Network Issue in Server Room", "35201-1234567-1", "Server Room, Floor 3", "Network Issue", "IT Support");
        inc1.reporterRole = "team_member";
        inc1.status = "Solved";
        incidents.push_back(inc1);
        incidentTypeCount["Network Issue"] = 1;
        
        Incident inc2("Software Bug in Payroll System", "35201-1234567-0", "Main Office", "Software Bug", "IT Support");
        inc2.reporterRole = "admin";
        incidents.push_back(inc2);
        incidentTypeCount["Software Bug"] = 1;
        
        Incident inc3("Employee Conflict", "35201-1234567-2", "HR Department", "Other", "HR Team");
        inc3.reporterRole = "team_head";
        incidents.push_back(inc3);
        incidentTypeCount["Other"] = 1;
        
        for (Incident& inc : incidents) {
            incidentQueue.enqueue(inc);
            priorityQueue.push(PriorityIncident(inc.id, inc.type, calculatePriority(inc.type)));
        }
        for (Team& team : teams) {
            if (team.name == "IT Support") {
                team.totalCases = 2;
                team.solvedCases = 1;
            }
            else if (team.name == "HR Team") {
                team.totalCases = 1;
                team.solvedCases = 0;
            }
        }
        
        logActivity("System initialized with default data");
    }

    void logActivity(string activity) {
        string logEntry = getCurrentTime() + " - " + activity;
        activityLog.push(logEntry);
    }

    void saveData() {
        ofstream empFile(EMP_FILE);
        for (Employee emp : employees) {
            empFile << emp.toFileString() << endl;
        }
        empFile.close();

        ofstream teamFile(TEAM_FILE);
        for (Team team : teams) {
            teamFile << team.toFileString() << endl;
        }
        teamFile.close();

        ofstream incFile(INC_FILE);
        for (Incident inc : incidents) {
            incFile << inc.toFileString() << endl;
        }
        incFile.close();
    }

    void loadData() {
        ifstream empFile(EMP_FILE);
        if (empFile.is_open()) {
            string line;
            while (getline(empFile, line)) {
                Employee emp = Employee::fromFileString(line);
                employees.push_back(emp);
                employeeMap[emp.username] = emp;
            }
            empFile.close();
        }

        ifstream teamFile(TEAM_FILE);
        if (teamFile.is_open()) {
            string line;
            while (getline(teamFile, line)) {
                Team team = Team::fromFileString(line);
                teams.push_back(team);
            }
            teamFile.close();
        }

        ifstream incFile(INC_FILE);
        if (incFile.is_open()) {
            string line;
            while (getline(incFile, line)) {
                Incident inc = Incident::fromFileString(line);
                incidents.push_back(inc);
                
                incidentTypeCount[inc.type]++;
                priorityQueue.push(PriorityIncident(inc.id, inc.type, calculatePriority(inc.type)));
            }
            incFile.close();
        }
    }
void normalUserMenu() {
        int choice;
        
        while(true) {
            cout << "\n" << string(40, '=') << "\n";
            cout << "      NORMAL USER MENU\n";
            cout << string(40, '=') << "\n";
            cout << "1. Report Incident\n";
            cout << "2. Back to Main Menu\n";
            cout << "Choice: ";
            cin >> choice;
            cin.ignore();
            
            if (choice == 1) {
                reportIncident();
                
                cout << "\nDo you want to see the full form? (1 for Yes, 0 for No): ";
                cin >> choice;
                cin.ignore();
                
                if (choice == 1 && !incidents.empty()) {
                    incidents.back().displayForm();
                }
            }
            else if (choice == 2) {
                break;
            }
            else {
                cout << "Invalid choice!\n";
            }
        }
    }

    void reportIncident() {
        string name, cnic, location, type;
        
        cout << "\n" << string(40, '=') << "\n";
        cout << "      REPORT NEW INCIDENT\n";
        cout << string(40, '=') << "\n";
        cout << "Enter Reporter Name: ";
        getline(cin, name);
        
        cout << "Enter Your CNIC: ";
        getline(cin, cnic);
        
        cout << "Enter Location: ";
        getline(cin, location);
        
        cout << "\nSELECT INCIDENT TYPE\n";
        cout << "   1. Hardware Failure\n";
        cout << "   2. Software Bug\n";
        cout << "   3. Network Issue\n";
        cout << "   4. Security Issue\n";
        cout << "   5. Other\n";
        cout << "Choice: ";
        
        int typeChoice;
        cin >> typeChoice;
        cin.ignore();
        
        switch(typeChoice) {
            case 1: type = "Hardware Failure"; break;
            case 2: type = "Software Bug"; break;
            case 3: type = "Network Issue"; break;
            case 4: type = "Security Issue"; break;
            default: type = "Other"; break;
        }
        
        string assignedTeam = "IT Support";
        string reporterRole = "Normal User";
        
        for (Employee emp : employees) {
            if (toLower(emp.cnic) == toLower(cnic)) {
                reporterRole = emp.role;
                assignedTeam = emp.team;
                cout << "\n Welcome " << emp.username << "!\n";
                cout << "  Role: " << reporterRole << "\n";
                cout << "  Team: " << assignedTeam << "\n";
                break;
            }
        }
        
        Incident incident(name, cnic, location, type, assignedTeam);
        incident.reporterRole = reporterRole;
        
        incidents.push_back(incident);
        incidentQueue.enqueue(incident);
        
        int priority = calculatePriority(type);
        priorityQueue.push(PriorityIncident(incident.id, type, priority));
        
        incidentTypeCount[type]++;
        
        bool teamFound = false;
        for (Team& team : teams) {
            if (team.name == assignedTeam) {
                team.totalCases++;
                teamFound = true;
                break;
            }
        }
        
        if (!teamFound) {
            cout << "Warning: Team '" << assignedTeam << "' not found!\n";
        }
        
        logActivity("New incident reported by " + cnic + ": " + name);
        cout << "\n Incident reported successfully!\n";
        cout << "  Incident ID: " << incident.id << "\n";
        cout << "  Assigned Team: " << assignedTeam << "\n";
    }

    int calculatePriority(string type) {
        return min(10, incidentTypeCount[type] + 1);
    }

    Employee* login() {
        string username, password;
        
        cout << "\n" << string(40, '=') << "\n";
        cout << "      EMPLOYEE LOGIN\n";
        cout << string(40, '=') << "\n";
        cout << "Username: ";
        getline(cin, username);
        
        cout << "Password: ";
        getline(cin, password);
        
        username = toLower(username);
        
        if (employeeMap.find(username) != employeeMap.end()) {
            Employee& emp = employeeMap[username];
            if (emp.password == password) {
                logActivity("User logged in: " + username);
                return &emp;
            }
        }
        
        cout << "\n Invalid credentials!\n";
        return NULL;
    }

    void adminMenu(Employee* admin) {
        int choice;
        
        do {
            cout << "\n" << string(40, '=') << "\n";
            cout << "        ADMIN MENU\n";
            cout << string(40, '=') << "\n";
            cout << "Welcome, " << admin->username << "\n";
            cout << string(40, '-') << "\n";
            cout << "1. Update Incident Status\n";
            cout << "2. Generate Reports\n";
            cout << "3. Add Employee\n";
            cout << "4. View All Employees\n";
            cout << "5. View All Teams\n";
            cout << "6. View Activity Log\n";
            cout << "7. Check Escalations\n";
            cout << "8. View Incident Queue\n";
            cout << "9. View Organization Hierarchy (Tree)\n";
            cout << "10. View Team Collaboration (Graph)\n";
            cout << "0. Logout\n";
            cout << "Choice: ";
            cin >> choice;
            cin.ignore();
            
            switch(choice) {
                case 1: updateStatus(); break;
                case 2: generateReports(); break;
                case 3: addEmployee(); break;
                case 4: viewEmployees(); break;
                case 5: viewAllTeams("All"); break;
                case 6: viewActivityLog(); break;
                case 7: checkEscalations(); break;
                case 8: viewIncidentQueue(); break;
                case 9: viewOrganizationHierarchy(); break;
                case 10: viewTeamCollaboration(); break;
                case 0: cout << "Logging out...\n"; break;
                default: cout << "Invalid choice!\n";
            }
        } while(choice != 0);
    }

    void updateStatus() {
        cout << "\n" << string(40, '=') << "\n";
        cout << "   UPDATE INCIDENT STATUS\n";
        cout << string(40, '=') << "\n";
        
        if (incidents.empty()) {
            cout << "No incidents to update!\n";
            return;
        }
        
        cout << "Recent Incidents:\n";
        int count = 0;
        for (int i = incidents.size() - 1; i >= 0 && count < 5; i--, count++) {
            cout << "ID: " << incidents[i].id << " | Type: " << incidents[i].type 
                 << " | Status: " << incidents[i].status << endl;
        }
        
        cout << "\nEnter Incident ID to update: ";
        int id;
        cin >> id;
        cin.ignore();
                
        bool found = false;
        for (Incident& inc : incidents) {
            if (inc.id == id) {
                found = true;
                cout << "\nCurrent Details:\n";
                cout << "|-- Report Name: " << inc.reportName << "\n";
                cout << "|-- Type: " << inc.type << "\n";
                cout << "|-- Current Status: " << inc.status << "\n";
                cout << "|-- Assigned Team: " << inc.assignedTeam << "\n";
                
                cout << "\nNew Status (Pending/In Progress/Solved): ";
                string newStatus;
                getline(cin, newStatus);
                
                inc.status = newStatus;
                
                if (newStatus == "Solved") {
                    for (Team& team : teams) {
                        if (team.name == inc.assignedTeam) {
                            team.solvedCases++;
                            break;
                        }
                    }
                    cout << " Incident marked as solved!\n";
                } else {
                    cout << " Status updated!\n";
                }
                
                logActivity("Incident " + to_string(id) + " status updated to " + newStatus);
                break;
            }
        }
        
        if (!found) {
            cout << " Incident not found!\n";
        }
    }

    void generateReports() {
        cout << "\n" << string(40, '=') << "\n";
        cout << "   INCIDENT STATISTICS REPORT\n";
        cout << string(40, '=') << "\n";
        
        if (incidents.empty()) {
            cout << "No incidents to report!\n";
            return;
        }
        
        map<string, int> typeCount;
        for (Incident inc : incidents) {
            typeCount[inc.type]++;
        }
        
        int total = incidents.size();
        
        cout << "\nIncident Type Distribution:\n";
        cout << string(50, '-') << "\n";
        cout << "Type\t\t\tCount\tPercentage\n";
        cout << string(50, '-') << "\n";
        
        for (auto& pair : typeCount) {
            string type = pair.first;
            int count = pair.second;
            float percentage = (float)count * 100 / total;
            
            cout << type;
            if (type.length() < 16) cout << "\t";
            cout << "\t" << count << "\t" << percentage << "%\n";
        }
        
        cout << string(50, '-') << "\n";
        cout << "Total Incidents: " << total << "\n";
        
        cout << "\nTeam Performance:\n";
        for (Team team : teams) {
            if (team.totalCases > 0) {
                cout << team.name << ": " << team.solvedCases << "/" 
                     << team.totalCases << " solved (" 
                     << (float)team.solvedCases * 100 / team.totalCases << "%)\n";
            }
        }
    }
    void addEmployee() {
        string username, password, cnic, role, team, dept;
        
        cout << "\n" << string(40, '=') << "\n";
        cout << "      ADD NEW EMPLOYEE\n";
        cout << string(40, '=') << "\n";
        cout << "Username: ";
        getline(cin, username);
        
        if (employeeMap.find(username) != employeeMap.end()) {
            cout << " Username already exists!\n";
            return;
        }
        
        cout << "Password: ";
        getline(cin, password);
        
        cout << "CNIC: ";
        getline(cin, cnic);
        
        cout << "Role (admin/team_head/team_member/dept_head): ";
        getline(cin, role);
        
        cout << "Department: ";
        getline(cin, dept);
        
        cout << "\nAvailable Teams:\n";
        for (int i = 0; i < teams.size(); i++) {
            cout << i+1 << ". " << teams[i].name << " (" << teams[i].department << ")\n";
        }
        
        cout << "Select Team (enter number): ";
        int teamChoice;
        cin >> teamChoice;
        cin.ignore();
        
        if (teamChoice < 1 || teamChoice > teams.size()) {
            cout << " Invalid team selection!\n";
            return;
        }
        
        team = teams[teamChoice-1].name;
        dept = teams[teamChoice-1].department;
        
        Employee newEmp(username, password, cnic, role, team, dept);
        employees.push_back(newEmp);
        employeeMap[username] = newEmp;
        
        teams[teamChoice-1].members.push_back(username);
        
        logActivity("New employee added: " + username);
        cout << "\n Employee added successfully!\n";
        cout << "  Username: " << username << "\n";
        cout << "  Team: " << team << "\n";
        cout << "  Department: " << dept << "\n";
        
        buildDataStructures();
    }
     void viewEmployees() {
        cout << "\n" << string(40, '=') << "\n";
        cout << "      ALL EMPLOYEES\n";
        cout << string(40, '=') << "\n";
        cout << "Total Employees: " << employees.size() << "\n";
        cout << string(40, '-') << "\n";
        
        if (employees.empty()) {
            cout << "No employees found!\n";
            return;
        }
        
        for (Employee emp : employees) {
            emp.display();
        }
    }

    void viewAllTeams(string dept) {
        cout << "\n" << string(40, '=') << "\n";
        cout << "        ALL TEAMS\n";
        cout << string(40, '=') << "\n";
        cout << "Total Teams: " << teams.size() << "\n";
        
        if (teams.empty()) {
            cout << "No teams found!\n";
            return;
        }
        
        for (Team team : teams) {
            team.display();
        }
    }
     void viewActivityLog() {
        cout << "\n" << string(40, '=') << "\n";
        cout << "     RECENT ACTIVITIES\n";
        cout << string(40, '=') << "\n";
        
        LinkedListStack<string> tempStack;
        int count = 0;
        
        while (!activityLog.isEmpty() && count < 10) {
            string activity = activityLog.pop();
            cout << activity << endl;
            tempStack.push(activity);
            count++;
        }
        
        while (!tempStack.isEmpty()) {
            activityLog.push(tempStack.pop());
        }
        
        if (count == 0) {
            cout << "No activities logged yet!\n";
        }
    }

    void viewIncidentQueue() {
        cout << "\n" << string(40, '=') << "\n";
        cout << "   INCIDENT QUEUE STATUS\n";
        cout << string(40, '=') << "\n";
        cout << "Total incidents in queue: " << incidentQueue.getSize() << "\n";
        
        cout << "\nPending Incidents:\n";
        int pendingCount = 0;
        for (Incident inc : incidents) {
            if (inc.status == "Pending") {
                cout << "ID: " << inc.id << " | Type: " << inc.type 
                     << " | Team: " << inc.assignedTeam << endl;
                pendingCount++;
            }
        }
        
        if (pendingCount == 0) {
            cout << "No pending incidents.\n";
        }
    }

    void checkEscalations() {
        cout << "\n" << string(40, '=') << "\n";
        cout << "      ESCALATION CHECK\n";
        cout << string(40, '=') << "\n";
        
        bool escalated = false;
        for (Incident& inc : incidents) {
            if (inc.status == "Pending" && inc.assignedTeam == "IT Support") {
                inc.assignedTeam = "Operations";
                inc.status = "Escalated";
                escalated = true;
                
                cout << " Incident " << inc.id << " escalated from IT Support to Operations\n";
                logActivity("Incident " + to_string(inc.id) + " escalated to Operations");
            }
        }
        
        if (!escalated) {
            cout << "No incidents need escalation at this time.\n";
        }
    }
  void viewOrganizationHierarchy() {
        orgTree.displayHierarchy();
        
        cout << "\nTree Functions:\n";
        cout << "1. View Manager of Employee\n";
        cout << "2. View Subordinates of Employee\n";
        cout << "3. View Escalation Path\n";
        cout << "Choice: ";
        
        int choice;
        cin >> choice;
        cin.ignore();
        
        if (choice == 1) {
            cout << "Enter employee username: ";
            string username;
            getline(cin, username);
            
            string manager = orgTree.getManager(username);
            if (manager.empty()) {
                cout << "No manager found or employee is admin.\n";
            } else {
                cout << "Manager of " << username << " is: " << manager << endl;
            }
        }
        else if (choice == 2) {
            cout << "Enter employee username: ";
            string username;
            getline(cin, username);
            
            vector<string> subordinates = orgTree.getSubordinates(username);
            if (subordinates.empty()) {
                cout << "No subordinates found.\n";
            } else {
                cout << "Subordinates of " << username << ":\n";
                for (const string& sub : subordinates) {
                    cout << "- " << sub << endl;
                }
            }
        }
        else if (choice == 3) {
            cout << "Enter employee username: ";
            string username;
            getline(cin, username);
            
            vector<string> path = orgTree.getEscalationPath(username);
            if (path.empty()) {
                cout << "No escalation path found.\n";
            } else {
                cout << "Escalation path for " << username << ":\n";
                for (size_t i = 0; i < path.size(); i++) {
                    cout << i+1 << ". " << path[i] << endl;
                }
            }
        }
    }

    void viewTeamCollaboration() {
        collabGraph.displayGraph();
        
        cout << "\nGraph Functions:\n";
        cout << "1. Find Experts for Incident Type\n";
        cout << "2. Find Team Collaborators\n";
        cout << "3. Find Shortest Path Between Employees\n";
        cout << "Choice: ";
        
        int choice;
        cin >> choice;
        cin.ignore();
        
        if (choice == 1) {
            cout << "Enter incident type: ";
            string incidentType;
            getline(cin, incidentType);
            
            vector<string> experts = collabGraph.findExperts(incidentType);
            if (experts.empty()) {
                cout << "No experts found.\n";
            } else {
                cout << "Top experts for " << incidentType << ":\n";
                for (size_t i = 0; i < experts.size(); i++) {
                    cout << i+1 << ". " << experts[i] << endl;
                }
            }
        }
        else if (choice == 2) {
            cout << "Enter team name: ";
            string teamName;
            getline(cin, teamName);
            
            vector<string> collaborators = collabGraph.findTeamCollaborators(teamName);
            if (collaborators.empty()) {
                cout << "No external collaborators found for team " << teamName << ".\n";
            } else {
                cout << "Collaborators for team " << teamName << ":\n";
                for (const string& collab : collaborators) {
                    cout << "- " << collab << endl;
                }
            }
        }
        else if (choice == 3) {
            cout << "Enter first employee username: ";
            string emp1;
            getline(cin, emp1);
            
            cout << "Enter second employee username: ";
            string emp2;
            getline(cin, emp2);
            
            vector<string> path = collabGraph.findShortestPath(emp1, emp2);
            if (path.empty()) {
                cout << "No path found between " << emp1 << " and " << emp2 << ".\n";
            } else {
                cout << "Shortest path between " << emp1 << " and " << emp2 << ":\n";
                for (size_t i = 0; i < path.size(); i++) {
                    cout << i+1 << ". " << path[i] << endl;
                }
                cout << "Path length: " << path.size()-1 << " connections\n";
            }
        }
    }

    void teamMenu(Employee* emp) {
        int choice;
        
        do {
            cout << "\n" << string(40, '=') << "\n";
            cout << "        TEAM MENU\n";
            cout << string(40, '=') << "\n";
            cout << "Welcome, " << emp->username << " (" << emp->role << ")\n";
            cout << "Team: " << emp->team << " | Department: " << emp->department << "\n";
            cout << string(40, '-') << "\n";
            cout << "1. View Assigned Cases\n";
            cout << "2. View Solved Cases\n";
            cout << "3. View Team Details\n";
            
            if (emp->role == "team_head") {
                cout << "4. Change Incident Status (Team Head Only)\n";
                cout << "5. View Team Members\n";
                cout << "6. View Team Collaboration Network\n";
            }
            
            if (emp->role == "dept_head") {
                cout << "7. Department Head Functions\n";
                cout << "8. View Organization Hierarchy\n";
            }
            
            cout << "0. Logout\n";
            cout << "Choice: ";
            cin >> choice;
            cin.ignore();
            
            switch(choice) {
                case 1: viewAssignedCases(emp->team); break;
                case 2: viewSolvedCases(emp->team); break;
                case 3: viewTeamDetails(emp->team); break;
                case 4: 
                    if (emp->role == "team_head") updateStatus(); 
                    else cout << " Access denied! Team head only.\n";
                    break;
                case 5: 
                    if (emp->role == "team_head") viewTeamMembers(emp->team); 
                    else cout << " Access denied! Team head only.\n";
                    break;
                case 6:
                    if (emp->role == "team_head") {
                        cout << "\nTeam Collaboration Network for " << emp->team << ":\n";
                        vector<string> collaborators = collabGraph.findTeamCollaborators(emp->team);
                        if (collaborators.empty()) {
                            cout << "No external collaborators found.\n";
                        } else {
                            for (const string& collab : collaborators) {
                                cout << "- " << collab << endl;
                            }
                        }
                    }
                    else cout << " Access denied! Team head only.\n";
                    break;
                case 7: 
                    if (emp->role == "dept_head") deptHeadMenu(emp); 
                    else cout << " Access denied! Department head only.\n";
                    break;
                case 8:
                    if (emp->role == "dept_head") orgTree.displayHierarchy();
                    else cout << " Access denied! Department head only.\n";
                    break;
                case 0: cout << "Logging out...\n"; break;
                default: cout << "Invalid choice!\n";
            }
        } while(choice != 0);
    }

    void viewAssignedCases(string team) {
        cout << "\n" << string(40, '=') << "\n";
        cout << "  ASSIGNED CASES FOR " << team << "\n";
        cout << string(40, '=') << "\n";
        
        bool found = false;
        for (Incident inc : incidents) {
            if (inc.assignedTeam == team && inc.status != "Solved") {
                cout << "\n--- Case " << inc.id << " ---\n";
                cout << "|-- Type: " << inc.type << "\n";
                cout << "|-- Reporter: " << inc.reporterCNIC << "\n";
                cout << "|-- Location: " << inc.location << "\n";
                cout << "|-- Status: " << inc.status << "\n";
                cout << "|-- Report Time: " << inc.reportTime << "\n";
                found = true;
            }
        }
        
        if (!found) {
            cout << "No assigned cases found!\n";
        }
    }

    void viewSolvedCases(string team) {
        cout << "\n" << string(40, '=') << "\n";
        cout << "   SOLVED CASES FOR " << team << "\n";
        cout << string(40, '=') << "\n";
        
        bool found = false;
        for (Incident inc : incidents) {
            if (inc.assignedTeam == team && inc.status == "Solved") {
                cout << "\n--- Case " << inc.id << " ---\n";
                cout << "|-- Type: " << inc.type << "\n";
                cout << "|-- Reporter: " << inc.reporterCNIC << "\n";
                cout << "|-- Location: " << inc.location << "\n";
                cout << "|-- Report Time: " << inc.reportTime << "\n";
                found = true;
            }
        }
        
        if (!found) {
            cout << "No solved cases found!\n";
        }
    }
    void viewTeamDetails(string teamName) {
        cout << "--------VIEWING TEAM DETAILS---------\n";
        
        bool found = false;
        for (Team team : teams) {
            if (team.name == teamName) {
                team.display();
                found = true;
                break;
            }
        }
        
        if (!found) {
            cout << " Team '" << teamName << "' not found!\n";
            cout << "Available teams:\n";
            for (Team t : teams) {
                cout << "- " << t.name << "\n";
            }
        }
    }

    void viewTeamMembers(string teamName) {
        cout << "\n" << string(40, '=') << "\n";
        cout << "  TEAM MEMBERS OF " << teamName << "\n";
        cout << string(40, '=') << "\n";
        
        for (Team team : teams) {
            if (team.name == teamName) {
                if (team.members.empty()) {
                    cout << "No members in this team.\n";
                } else {
                    cout << "Total Members: " << team.members.size() << "\n";
                    cout << string(40, '-') << "\n";
                    for (int i = 0; i < team.members.size(); i++) {
                        cout << i+1 << ". " << team.members[i] << "\n";
                        
                        if (employeeMap.find(team.members[i]) != employeeMap.end()) {
                            Employee emp = employeeMap[team.members[i]];
                            cout << "   Role: " << emp.role << ", CNIC: " << emp.cnic << "\n";
                        }
                    }
                }
                return;
            }
        }
        cout << " Team not found!\n";
    }

    void deptHeadMenu(Employee* deptHead) {
        int choice;
        
        do {
            cout << "\n" << string(40, '=') << "\n";
            cout << "  DEPARTMENT HEAD MENU\n";
            cout << string(40, '=') << "\n";
            cout << "Department: " << deptHead->department << "\n";
            cout << string(40, '-') << "\n";
            cout << "1. View All Teams in Department\n";
            cout << "2. View All Cases in Department\n";
            cout << "3. Add Team Member\n";
            cout << "4. Remove Team Member\n";
            cout << "5. View Department Collaboration Graph\n";
            cout << "0. Back to Team Menu\n";
            cout << "Choice: ";
            cin >> choice;
            cin.ignore();
            
            switch(choice) {
                case 1: viewDeptTeams(deptHead->department); break;
                case 2: viewDeptCases(deptHead->department); break;
                case 3: addTeamMember(deptHead->department); break;
                case 4: removeTeamMember(deptHead->department); break;
                case 5: viewDeptCollaboration(deptHead->department); break;
                case 0: break;
                default: cout << "Invalid choice!\n";
            }
        } while(choice != 0);
    }

    void viewDeptTeams(string dept) {
        cout << "\n" << string(40, '=') << "\n";
        cout << "  TEAMS IN " << dept << " DEPARTMENT\n";
        cout << string(40, '=') << "\n";
        
        bool found = false;
        for (Team team : teams) {
            if (team.department == dept) {
                team.display();
                found = true;
            }
        }
        
        if (!found) {
            cout << "No teams found in this department!\n";
        }
    }

    void viewDeptCases(string dept) {
        cout << "\n" << string(40, '=') << "\n";
        cout << "  CASES IN " << dept << " DEPARTMENT\n";
        cout << string(40, '=') << "\n";
        
        vector<string> deptTeams;
        for (Team team : teams) {
            if (team.department == dept) {
                deptTeams.push_back(team.name);
            }
        }
        
        if (deptTeams.empty()) {
            cout << "No teams in this department!\n";
            return;
        }
        
        bool found = false;
        for (Incident inc : incidents) {
            for (string teamName : deptTeams) {
                if (inc.assignedTeam == teamName) {
                    cout << "\n--- Case " << inc.id << " ---\n";
                    cout << "|-- Team: " << inc.assignedTeam << "\n";
                    cout << "|-- Type: " << inc.type << "\n";
                    cout << "|-- Status: " << inc.status << "\n";
                    cout << "|-- Reporter: " << inc.reporterCNIC << "\n";
                    found = true;
                    break;
                }
            }
        }
        
        if (!found) {
            cout << "No cases found in this department!\n";
        }
    }

    void viewDeptCollaboration(string dept) {
        cout << "\n" << string(40, '=') << "\n";
        cout << "  COLLABORATION IN " << dept << " DEPARTMENT\n";
        cout << string(40, '=') << "\n";
        
        for (const Employee& emp : employees) {
            if (emp.department == dept) {
                cout << "\n" << emp.username << " (" << emp.role << "):\n";
                
                vector<string> path = collabGraph.findShortestPath(emp.username, "admin");
                if (!path.empty()) {
                    cout << "Path to admin: ";
                    for (size_t i = 0; i < path.size(); i++) {
                        cout << path[i];
                        if (i < path.size() - 1) cout << " → ";
                    }
                    cout << endl;
                }
            }
        }
    }

    void addTeamMember(string dept) {
        cout << "\n" << string(40, '=') << "\n";
        cout << "      ADD TEAM MEMBER\n";
        cout << string(40, '=') << "\n";
        
        cout << "Teams in " << dept << " department:\n";
        vector<string> deptTeamNames;
        int index = 1;
        for (Team team : teams) {
            if (team.department == dept) {
                cout << index << ". " << team.name << "\n";
                deptTeamNames.push_back(team.name);
                index++;
            }
        }
        
        if (deptTeamNames.empty()) {
            cout << "No teams in this department!\n";
            return;
        }
        
        cout << "\nSelect team (enter number): ";
        int teamChoice;
        cin >> teamChoice;
        cin.ignore();
        
        if (teamChoice < 1 || teamChoice > deptTeamNames.size()) {
            cout << " Invalid selection!\n";
            return;
        }
        
        string selectedTeam = deptTeamNames[teamChoice-1];
        
        cout << "\nAvailable Employees:\n";
        vector<string> availableEmps;
        index = 1;
        for (Employee emp : employees) {
            if (emp.department == dept && emp.team != selectedTeam) {
                cout << index << ". " << emp.username << " (currently in " << emp.team << ")\n";
                availableEmps.push_back(emp.username);
                index++;
            }
        }
        
        if (availableEmps.empty()) {
            cout << "No available employees to add!\n";
            return;
        }
        
        cout << "\nSelect employee to add (enter number): ";
        int empChoice;
        cin >> empChoice;
        cin.ignore();
        
        if (empChoice < 1 || empChoice > availableEmps.size()) {
            cout << " Invalid selection!\n";
            return;
        }
        
        string selectedEmp = availableEmps[empChoice-1];
        
        for (Team& team : teams) {
            if (team.name == selectedTeam) {
                team.members.push_back(selectedEmp);
                
                for (Employee& emp : employees) {
                    if (emp.username == selectedEmp) {
                        emp.team = selectedTeam;
                        employeeMap[selectedEmp].team = selectedTeam;
                        break;
                    }
                }
                
                cout << "\n " << selectedEmp << " added to " << selectedTeam << " team!\n";
                logActivity(selectedEmp + " added to team " + selectedTeam);
            
                collabGraph.addEmployee(selectedEmp, selectedTeam);
                for (const string& member : team.members) {
                    if (member != selectedEmp) {
                        collabGraph.addCollaboration(selectedEmp, member);
                    }
                }
                
                return;
            }
        }
        
        cout << " Team not found!\n";
    }

    void removeTeamMember(string dept) {
        cout << "\n" << string(40, '=') << "\n";
        cout << "    REMOVE TEAM MEMBER\n";
        cout << string(40, '=') << "\n";
        
        cout << "Teams in " << dept << " department:\n";
        vector<string> deptTeamNames;
        int index = 1;
        for (Team team : teams) {
            if (team.department == dept) {
                cout << index << ". " << team.name << "\n";
                deptTeamNames.push_back(team.name);
                index++;
            }
        }
        
        if (deptTeamNames.empty()) {
            cout << "No teams in this department!\n";
            return;
        }
        
        cout << "\nSelect team (enter number): ";
        int teamChoice;
        cin >> teamChoice;
        cin.ignore();
        
        if (teamChoice < 1 || teamChoice > deptTeamNames.size()) {
            cout << " Invalid selection!\n";
            return;
        }
        
        string selectedTeam = deptTeamNames[teamChoice-1];
        
        Team* targetTeam = nullptr;
        for (Team& team : teams) {
            if (team.name == selectedTeam) {
                targetTeam = &team;
                break;
            }
        }
        
        if (!targetTeam || targetTeam->members.empty()) {
            cout << "No members in this team!\n";
            return;
        }
        
        cout << "\nMembers in " << selectedTeam << ":\n";
        for (int i = 0; i < targetTeam->members.size(); i++) {
            cout << i+1 << ". " << targetTeam->members[i] << "\n";
        }
        
        cout << "\nSelect member to remove (enter number): ";
        int memChoice;
        cin >> memChoice;
        cin.ignore();
        
        if (memChoice < 1 || memChoice > targetTeam->members.size()) {
            cout << " Invalid selection!\n";
            return;
        }
        
        string memberToRemove = targetTeam->members[memChoice-1];
        
        targetTeam->members.erase(targetTeam->members.begin() + memChoice - 1);
        
        for (Employee& emp : employees) {
            if (emp.username == memberToRemove) {
                emp.team = "Unassigned";
                employeeMap[memberToRemove].team = "Unassigned";
                break;
            }
        }
    
        cout << "\n " << memberToRemove << " removed from " << selectedTeam << " team!\n";
        logActivity(memberToRemove + " removed from team " + selectedTeam);
    }

    void run() {
        int choice;
        
        while(true) {
            cout << "\n" << string(50, '=') << "\n";
            cout << "       INCIDENT MANAGEMENT SYSTEM\n";
            cout << string(50, '=') << "\n";
            cout << "1. Report Incident\n";
            cout << "2. Employee Login\n";
            cout << "3. View Priority Queue\n";
            cout << "4. View System Status\n";
            cout << "5. Exit System\n";  
            cout << string(50, '-') << "\n";
            cout << "Choice: ";
            
            cin >> choice;
            cin.ignore();
            
            switch(choice) {
                case 1: 
                    normalUserMenu(); 
                    break;
                case 2: {
                    Employee* loggedIn = login();
                    if (loggedIn) {
                        if (loggedIn->role == "admin") {
                            adminMenu(loggedIn);
                        } else {
                            teamMenu(loggedIn);
                        }
                    }
                    break;
                }
                case 3:
                    priorityQueue.display();
                    break;
                case 4:
                    showSystemStatus();
                    break;
                case 5: 
                    cout << "\nSaving data...\n";
                    cout << "Thank you for using the Incident Management System!\n";
                    saveData();
                    return;
                default:
                    cout << "Invalid choice! Please try again.\n";
            }
        }
    }

    void showSystemStatus() {
        cout << "\n" << string(50, '=') << "\n";
        cout << "          SYSTEM STATUS\n";
        cout << string(50, '=') << "\n";
        cout << "|-- Total Employees: " << employees.size() << "\n";
        cout << "|-- Total Teams: " << teams.size() << "\n";
        cout << "|-- Total Incidents: " << incidents.size() << "\n";
        cout << "|-- Incident Queue Size: " << incidentQueue.getSize() << "\n";
        cout << "|-- Activity Log Size: " << activityLog.getSize() << "\n";
        cout << "|-- Priority Queue Size: " << (priorityQueue.isEmpty() ? 0 : "Non-empty") << "\n";
        
        cout << "\nTeams Overview:\n";
        for (Team team : teams) {
            cout << "|-- " << team.name << ":\n";
            cout << "|  |-- Department: " << team.department << "\n";
            cout << "|  |-- Members: " << team.members.size() << "\n";
            cout << "|  |-- Cases: " << team.totalCases << " (Solved: " << team.solvedCases << ")\n";
        }
        
        cout << "\nRecent Incidents:\n";
        int count = 0;
        for (int i = incidents.size() - 1; i >= 0 && count < 5; i--, count++) {
            cout << "ID: " << incidents[i].id << " | Type: " << incidents[i].type 
                 << " | Status: " << incidents[i].status 
                 << " | Team: " << incidents[i].assignedTeam << endl;
        }
        
        if (incidents.empty()) {
            cout << "No incidents reported yet.\n";
        }
    }
};

int main() {
    cout<<"\n"<<string(60, '*')<<"\n";
    cout<< "    WELCOME TO INCIDENT MANAGEMENT SYSTEM\n";
    cout<<string(60, '*')<<"\n\n";
    
    IncidentSystem system;
    system.run();
    
    return 0;
}