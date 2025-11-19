#include <bits/stdc++.h>
using namespace std;

class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
      
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };
   
    int currentSize;                          
    int maxCapacity;                          
    Node* dummyHead;                         
    Node* dummyTail;                         
    unordered_map<int, Node*> keyToNode;   
  
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
  
    void addToHead(Node* node) {
        node->next = dummyHead->next;
        node->prev = dummyHead;
        dummyHead->next->prev = node;
        dummyHead->next = node;
    }
  
public:
    LRUCache(int capacity) : currentSize(0), maxCapacity(capacity) {
        dummyHead = new Node(0, 0);
        dummyTail = new Node(0, 0);
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
    }
  
    int get(int key) {
        if (keyToNode.find(key) == keyToNode.end()) {
            return -1;
        }
      
        Node* node = keyToNode[key];
        removeNode(node);
        addToHead(node);
      
        return node->value;
    }
  
    void put(int key, int value) {
        if (keyToNode.find(key) != keyToNode.end()) {
            Node* node = keyToNode[key];
            removeNode(node);
            node->value = value;
            addToHead(node);
        } 
        else {
            Node* newNode = new Node(key, value);
            keyToNode[key] = newNode;
            addToHead(newNode);
            currentSize++;
          
            if (currentSize > maxCapacity) {
                Node* lruNode = dummyTail->prev;
                keyToNode.erase(lruNode->key);
                removeNode(lruNode);
                delete lruNode;  // Free memory
                currentSize--;
            }
        }
    }
};


int main() {

    return 0;
}