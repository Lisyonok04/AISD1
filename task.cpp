#pragma once
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
struct Node {
	int _val;
	Node<T>* _left;
	Node<T>* _right;

	Node(int val) :_val(val), _left(nullptr), _right(nullptr) {};
	Node(int val, Node<T>* left, Node<T>* right) :_val(val), _left(left), _right(right) {};
};

template<typename T>
class Tree {
private:
    Node<T>* root;
    
    void clear(Node<T>* node) {
        if (node) {
            clear(node->_left);
            clear(node->_right);
            delete node;
        }
    }

    void print(Node<T>* node) {
        if (node) {
            print(node->_left);
            std::cout << node->_val << " ";
            print(node->_right);
        }
    }

	bool insert(Node<T>*& node, T key) {
		if (!node) {
			node = new Node<T>(key);
			return true;
		}
		if (node->_val > key) {
			return insert(node->_left, key);
		}
		else if (node->_val < key) {
			return insert(node->_right, key);
		}
		return false;
	}