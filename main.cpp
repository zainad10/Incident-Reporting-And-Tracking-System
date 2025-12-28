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

