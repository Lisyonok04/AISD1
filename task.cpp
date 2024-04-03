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

	bool erase(Node<T>*& node, T value) {
		if (!node) {
			return false;
		}
		if (value < node->_val) {
			return erase(node->_left, value);
		}
		else if (value > node->_val) {
			return erase(node->_right, value);
		}
		else {
			if (!node->_left) {
				Node<T>* temp = node->_right;
				delete node;
				node = temp;
			}
			else if (!node->_right) {
				Node<T>* temp = node->_left;
				delete node;
				node = temp;
			}
			else {
				Node<T>* temp = node->_right;
				while (temp->_left) {
					temp = temp->_left;
				}
				node->_val = temp->_val;
				erase(node->_right, temp->_val);
			}
			return true;
		};
	}
public:
	Tree() : root(nullptr) {}
	Tree(const Tree<T>& other) {
		root = copy(other.root);
	}
	~Tree() {
		clear(root);
	}
	bool insert(T value) {
		return insert(root, value);
	}
	void print() {
		print(root);
		std::cout << std::endl;
	}
	bool eraser(T value) {
		return erase(root, value);
	}
};