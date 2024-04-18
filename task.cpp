#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <random>
#include <chrono>

using namespace std;


class Randomize {
private:
	int _seed;
	int _min;
	int _max;
public:
	Randomize() : _seed(0), _min(0), _max(1) {};
	Randomize(int seed, int min, int max) : _seed(seed), _min(min), _max(max) {};
	int generate_random_number() {
		mt19937 mt(_seed);
		uniform_int_distribution<int> distribution(_min, _max);
		_seed++;
		return distribution(mt);
	}
};
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

	Node<T>* copy(Node<T>* node) {
		if (!node) {
			return nullptr;
		}
		Node<T>* new_node = new Node<T>(node->_val);
		new_node->_left = copy(node->_left);
		new_node->_right = copy(node->_right);
		return new_node;
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
		/*else if (node->_val == key) {
			return insert(node->_right, 0);
		}*/
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
	Tree(Node<T>* node) {
		root = new Node<T>(node->_val, node->_left, node->_right);
	}
	Tree(const Tree<T>& other) {
		root = copy(other.root);
	}
	Tree(const vector<T>& other) {
		root = nullptr;
		for (auto vec : other) {
			inserter(vec);
		}
	}
	~Tree() {
		clear(root);
	}

	Tree<T>& filling(size_t count) {
		size_t cur_count = 0;
		Randomize test_seed(0, 0, count * 10);
		while (cur_count != count) {
			if (inserter(test_seed.generate_random_number()))
				cur_count++;
		}
		return *this;
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

template <typename T>
vector<T> unique(const vector<T>& vec) {
	Tree<T> before(vec);
	//before.print();
	vector<T> after = {};
	size_t count = get_elements(before.getroot());
	//cout << before.getroot()->_val << endl;
	for (int j = 0; j < count; j++) {
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
}

double get_time_filling(size_t count) {
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i <= 100; i++) {
		Tree<int> test_set;
		test_set.filling(count);
	}
	auto end = std::chrono::high_resolution_clock::now();
	double rezult = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 100;
	return rezult / count;
}

double get_time_contains(Tree<int>& test_set, size_t count) {
	Randomize test_seed(0, 0, count * 10);
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i <= 1000; i++) {
		test_set.contains(test_seed.generate_random_number());
	}
	auto end = std::chrono::high_resolution_clock::now();
	double rezult = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000;
	return rezult / count;
}
double get_time_erase(Tree<int>& test_set, size_t count) {
	Randomize test_seed(0, 0, count * 10);
	Tree test_set_copy(test_set);
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i <= 1000; i++) {
		test_set_copy.eraser(test_seed.generate_random_number());
	}
	auto end = std::chrono::high_resolution_clock::now();
	double rezult = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000;
	return rezult / count;
}
double get_time_insert(Tree<int>& test_set, size_t count) {
	Randomize test_seed(0, 0, count * 10);
	Tree test_set_copy(test_set);
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i <= 1000; i++) {
		test_set_copy.inserter(test_seed.generate_random_number());
	}
	auto end = std::chrono::high_resolution_clock::now();
	double rezult = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	return rezult / count;
}


double get_time_filling_vector(size_t count) {
	Randomize test_seed(0, 0, count * 10);
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i <= 100; i++) {
		vector<int> test_vec;
		for (int i = 0; i <= count; i++)
			test_vec.push_back(test_seed.generate_random_number());
	}
	auto end = std::chrono::high_resolution_clock::now();
	double rezult = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 100;
	return rezult / count;
}
double get_time_contains_vector(vector<int>& arr, size_t count) {
	Randomize test_seed(0, 0, count * 10);
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i <= 1000; i++) {
		find(arr.begin(), arr.end(), test_seed.generate_random_number());
	}
	auto end = std::chrono::high_resolution_clock::now();
	double rezult = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000;
	return rezult / count;
}
double get_time_erase_vector(vector<int>& test_set, size_t count) {
	Randomize test_seed(0, 0, count * 10);
	vector<int> test_vec_copy(test_set);
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i <= 1000; i++) {
		const auto del_obj = remove(test_vec_copy.begin(), test_vec_copy.end(), test_seed.generate_random_number());
		test_vec_copy.erase(del_obj, test_vec_copy.end());
	}
	auto end = std::chrono::high_resolution_clock::now();
	double rezult = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000;
	return rezult / count;
}
double get_time_insert_vector(vector<int>& test_set, size_t count) {
	Randomize test_seed(0, 0, count * 10);
	vector<int> test_vec_copy = test_set;
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i <= 1000; i++) {
		test_vec_copy.push_back(test_seed.generate_random_number());
	}
	auto end = std::chrono::high_resolution_clock::now();
	double rezult = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	return rezult / count;
}
