#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    void f(Node* root, Node* node, vector<Node*> &visited){
        for(auto neigh : node->neighbors){
            if(!visited[neigh->val]){
                Node* newnode = new Node(neigh->val);
                visited[neigh->val] = newnode;
                root->neighbors.push_back(newnode);
                f(newnode, neigh, visited);
            } else{
                root->neighbors.push_back(visited[neigh->val]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        vector<Node*> visited(110, NULL);
        Node* root = new Node(node->val);
        visited[root->val] = root;
        f(root, node, visited);
        return root;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> visited;
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        if (visited.count(node)) return visited[node];
        Node* clone = new Node(node->val);
        visited[node] = clone;
        for (auto neigh : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neigh));
        }
        return clone;
    }
};


int main() {

    return 0;
}