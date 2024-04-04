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
	bool contain(Node<T>* node, T value) {
		if (!node) {
			return false;
		}
		if (value < node->_val) {
			return contain(node->_left, value);
		}
		else if (value > node->_val) {
			return contain(node->_right, value);
		}
		return true;
	}
public:
	Tree() : root(nullptr) {}
	Tree(const Tree<T>& other) {
		root = copy(other.root);
	}
	~Tree() {
		clear(root);
	}
	Tree<T>& operator=(const Tree<T>& other) {
		if (this != &other) {
			clear(root);
			root = copy(other.root);
		}
		return *this;
	}
	bool inserter(T value) {
		return insert(root, value);
	}
	void print() {
		print(root);
		std::cout << std::endl;
	}
	bool eraser(T value) {
		return erase(root, value);
	}
	bool contains(T value) {
		return contain(root, value);
	}
	Node<T>* getroot() {
		return root;
	}

};

template <typename T>
size_t get_elements(Node<T>* root) {
	if (!root) return 0;
	return get_elements(root->_left) + get_elements(root->_right) + 1;
}

/*template <typename T>
vector<T> unique(const vector<T>& vec) {
	Tree<T> before(vec);
	vector<T> after = {};
	size_t sas = get_elements(before.getroot());
	for (int j = 0; j < sas; j++) {
		int counter = 0;
		for (int i = 0; i < vec.size(); i++) {
			if (before.getroot()->_val == vec[i]) {
				counter++;
			}
		}
		if (counter == 1) {
			after.push_back(before.getroot()->_val);
		}
		before.eraser(before.getroot()->_val);
	}
	return after;
}*/